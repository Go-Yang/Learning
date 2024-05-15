#include <iostream>
#include <fstream>
#include <windows.h>     // 包含Windows API头文件
#include "./json.hpp" // 包含json.hpp头文件
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using json = nlohmann::json;
using namespace std;

void showMap() {
    // 显示栅格图像的功能
}

int main() {
    // 创建一个空白图像，大小为 1200x1200，颜色为白色
    cv::Mat image(1200, 1200, CV_8UC3, cv::Scalar(255, 255, 255));

    // 定义线段的起点和终点坐标
    cv::Point start(100, 200);
    cv::Point end(400, 400);

    // 绘制线段，颜色为红色，线宽为2
    cv::line(image, start, end, cv::Scalar(0, 0, 255), 2);

    // 显示图像
    cv::imshow("Line", image);
    cv::waitKey(0);

    // 初始化OPENFILENAME结构体
    OPENFILENAME ofn;
    char szFile[260] = {0}; // 存储文件名的缓冲区
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "JSON Files (*.json)\0*.json\0All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrFileTitle = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

    // 打开文件对话框
    if (GetOpenFileName(&ofn) == TRUE) {
        // 用户选择了一个文件，获取文件路径并打开文件
        ifstream file(ofn.lpstrFile);
        if (file.is_open()) {
            // 读取文件内容
            cout << "File opened successfully! File path: " << ofn.lpstrFile << endl;

            // 解析JSON数据
            json j;
            file >> j;
            file.close();
            // 输出解析后的JSON数据
            cout << "Parsed JSON:" << endl;
            cout << j.dump(4) << endl;

            // 此处操作 //
            vector<vector<cv::Point>> m_Areas;
            int areaid = 0;
            while (!j["area_" + to_string(areaid)].is_null()) {
                cout << "Parsed area: " << areaid << endl;
                vector<cv::Point> polygon;

                if (!j["area_" + to_string(areaid)]["polygon"].is_null()) {
                    int dotid = 0;
                    while (dotid < j["area_" + to_string(areaid)]["polygon"].size()) {
                        int x = j["area_" + to_string(areaid)]["polygon"][dotid][0];
                        int y = j["area_" + to_string(areaid)]["polygon"][dotid][1];
                        polygon.push_back(cv::Point(x, y));
                        dotid++;
                    }
                }
                m_Areas.push_back(polygon);
                areaid++;
            }

            // 绘制多边形区域
            for (const auto& area : m_Areas) {
                // 至少有两个点才能绘制多边形
                if (area.size() < 2) continue;

                for (size_t i = 0; i < area.size() - 1; i++) {
                    cv::line(image, area[i], area[i + 1], cv::Scalar(0, 0, 255), 2);
                }
                // 连接最后一个点到第一个点
                cv::line(image, area.back(), area.front(), cv::Scalar(0, 0, 255), 2);
            }

            // 显示图像
            cv::imshow("Map", image);
            cv::waitKey(0);
        } else {
            cout << "Failed to open file!" << endl;
        }
    } else {
        // 用户取消了文件选择操作
        cout << "File selection canceled by user." << endl;
    }

    return 0;
}
