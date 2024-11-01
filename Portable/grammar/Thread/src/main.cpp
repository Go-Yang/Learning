#include <iostream>
#include <mingw.thread.h>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>

std::mutex mtx;
std::condition_variable cv;
bool flag = true;

void tt() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return flag;});
        std::cout << "Hello from thread tt!" << std::endl;
        flag = false;
        cv.notify_one();
    }
}

void qq() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !flag;});
        std::cout << "Hello from thread qq!" << std::endl;
        flag = true;
        cv.notify_one();
    }
}

int main() {
    std::thread t(tt);
    std::thread q(qq);

    t.join();
    q.join();

    return 0;
}
