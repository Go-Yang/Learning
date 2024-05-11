#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <thread>

class MapNode
{
private:
    // 私有结构体
    struct Map {
        
    };

public:
    static MapNode &Instance()
    {
        static MapNode instance; // 首次调用时初始化
        return instance;
    }
    

private:
    MapNode() {}
    // 禁止拷贝构造函数和赋值运算符
    MapNode(const MapNode &) = delete;
    MapNode &operator=(const MapNode &) = delete;
};

int main()
{

    return 0;
}
