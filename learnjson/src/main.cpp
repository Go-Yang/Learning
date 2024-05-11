#include <iostream>
#include <fstream>
#include <windows.h> // 包含Windows API头文件
#include "json/json.hpp" // 包含json.hpp头文件

using json = nlohmann::json;
using namespace std;

int main() {
    // 初始化OPENFILENAME结构体
    OPENFILENAME ofn;
    char szFile[260] = { 0 }; // 存储文件名的缓冲区
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
            // 输出解析后的JSON数据
            cout << "Parsed JSON:" << endl;
            cout << j.dump(4) << endl;

            file.close();
        } else {
            cout << "Failed to open file!" << endl;
        }
    } else {
        // 用户取消了文件选择操作
        cout << "File selection canceled by user." << endl;
    }

    return 0;
}
