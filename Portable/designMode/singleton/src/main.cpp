#include <iostream>
#include "Singleton.hpp"

int main() {
    std::cout << "Testing Singleton..." << std::endl;
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    if (instance1 == instance2) {
        std::cout << "Singleton works!" << std::endl;
    } else {
        std::cout << "Singleton failed!" << std::endl;
    }
    std::cout << "Singleton1 : " << instance1 << std::endl;
    std::cout << "Singleton2 : " << instance2 << std::endl;

    // 调用 showMessage() 来确保输出
    instance1->showMessage();  // 这里应该输出 "Singleton works!"
    Singleton::destroyInstance(); // 清理实例
    
    return 0;
}
