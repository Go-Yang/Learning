#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>

class Singleton {
public:
    static Singleton* getInstance();
    static void destroyInstance();
    void showMessage();

private:
    Singleton();                          // 构造函数私有
    ~Singleton();                         // 析构函数私有
    Singleton(const Singleton&) = delete; // 禁用拷贝构造
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
    static std::mutex mutex_;
};

#endif // SINGLETON_H
