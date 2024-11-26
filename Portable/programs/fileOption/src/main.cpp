// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <filesystem>

// namespace fs = std::filesystem;

// class FileManager {
// public:
//     // 写入数据到文件
//     static void writeToFile(const std::string& filename, const std::string& content) {
//         std::ofstream file(filename, std::ios::out | std::ios::trunc); // 打开文件，清空内容
//         if (file.is_open()) {
//             file << content; // 写入内容
//             file.close();
//             std::cout << "内容已写入文件：" << filename << std::endl;
//         } else {
//             std::cerr << "无法打开文件进行写入：" << filename << std::endl;
//         }
//     }

//     // 从文件中读取数据
//     static std::string readFromFile(const std::string& filename) {
//         std::ifstream file(filename);
//         std::string content;

//         if (file.is_open()) {
//             std::ostringstream ss;
//             ss << file.rdbuf(); // 读取文件内容
//             content = ss.str();
//             file.close();
//             std::cout << "内容已读取自文件：" << filename << std::endl;
//         } else {
//             std::cerr << "无法打开文件进行读取：" << filename << std::endl;
//         }

//         return content;
//     }

//     // 修改文件中的内容（在文件中找到特定字符串进行替换）
//     static void modifyFile(const std::string& filename, const std::string& oldStr, const std::string& newStr) {
//         std::ifstream file(filename);
//         if (!file.is_open()) {
//             std::cerr << "无法打开文件进行修改：" << filename << std::endl;
//             return;
//         }

//         std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//         file.close();

//         size_t pos = content.find(oldStr);
//         if (pos != std::string::npos) {
//             content.replace(pos, oldStr.length(), newStr); // 替换内容
//             std::ofstream outFile(filename, std::ios::out | std::ios::trunc); // 打开文件进行写入
//             outFile << content; // 将修改后的内容写回文件
//             outFile.close();
//             std::cout << "文件已修改：" << filename << std::endl;
//         } else {
//             std::cout << "未找到需要修改的内容：" << oldStr << std::endl;
//         }
//     }

//     // 删除文件
//     static void deleteFile(const std::string& filename) {
//         if (fs::exists(filename)) {
//             fs::remove(filename);
//             std::cout << "文件已删除：" << filename << std::endl;
//         } else {
//             std::cerr << "文件不存在：" << filename << std::endl;
//         }
//     }
// };

// int main() {
//     const std::string filename = "example.txt";

//     // 写入文件
//     FileManager::writeToFile(filename, "Hello, this is a test file.\nThis is the second line.");

//     // 读取文件
//     std::string content = FileManager::readFromFile(filename);
//     std::cout << "文件内容：\n" << content << std::endl;

//     // 修改文件内容
//     FileManager::modifyFile(filename, "second", "third");

//     // 读取修改后的文件
//     content = FileManager::readFromFile(filename);
//     std::cout << "修改后的文件内容：\n" << content << std::endl;

//     // 删除文件
//     FileManager::deleteFile(filename);

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>

namespace fs = std::filesystem;
using json = nlohmann::json;

class FileManager {
public:
    // 读取 JSON 文件
    static json readJsonFile(const std::string& filename) {
        std::ifstream file(filename);
        json j;
        if (file.is_open()) {
            file >> j;  // 读取 JSON 数据
            file.close();
        } else {
            std::cerr << "无法打开文件 " << filename << std::endl;
        }
        return j;
    }

    // 写入 JSON 文件
    static void writeJsonFile(const std::string& filename, const json& j) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << j.dump(4);  // 格式化输出，缩进 4
            file.close();
        } else {
            std::cerr << "无法写入文件 " << filename << std::endl;
        }
    }

    // 遍历目录并读取 JSON 文件
    static void traverseDirectoryAndReadJson(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ".json") {
                std::cout << "正在读取文件: " << entry.path() << std::endl;
                json j = readJsonFile(entry.path().string());
                std::cout << "内容: " << j.dump(4) << std::endl;
            }
        }
    }

    // 修改并写回 JSON 文件
    static void modifyJsonFile(const std::string& filename, const std::string& key, const json& value) {
        json j = readJsonFile(filename);
        j[key] = value;  // 修改指定的键值
        writeJsonFile(filename, j);
    }
};

int main() {
    // 写入一个简单的 JSON 文件
    json j1 = {
        {"name", "Alice"},
        {"age", 30},
        {"city", "Wonderland"}
    };
    const std::string filename = "example.json";
    FileManager::writeJsonFile(filename, j1);

    // 读取并输出 JSON 文件内容
    json j2 = FileManager::readJsonFile(filename);
    std::cout << "读取的 JSON 文件内容：" << std::endl;
    std::cout << j2.dump(4) << std::endl;

    // 修改 JSON 文件
    FileManager::modifyJsonFile(filename, "age", 31);
    std::cout << "修改后的 JSON 文件内容：" << std::endl;
    json j3 = FileManager::readJsonFile(filename);
    std::cout << j3.dump(4) << std::endl;

    // 遍历目录并读取所有 JSON 文件
    std::cout << "\n遍历目录读取 JSON 文件：" << std::endl;
    FileManager::traverseDirectoryAndReadJson(".");

    return 0;
}
