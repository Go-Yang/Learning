#include "Singleton.hpp"
#include <iostream>
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex_;

Singleton::Singleton() {
    // 初始化逻辑
    std::cout << "Singleton creat success!" << std::endl;
}

Singleton::~Singleton() {
    // 清理逻辑
    std::cout << "Singleton destroy success!" << std::endl;
}

Singleton* Singleton::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!instance) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::destroyInstance() {
    mutex_.lock();
    delete instance;
    instance = nullptr;
    mutex_.unlock();
}

void Singleton::showMessage() {
    // 显示消息
    std::cout << "Singleton address: "<< this << std::endl;
}
