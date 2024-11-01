#include <iostream>
using namespace std;

/*
malloc 和 free 是 C 的库函数
new 和 delete 是运算符

new 开辟内存还能初始化
malloc 失败用返回值判断 vs new 失败用bad_alloc类型的异常判断
*/

int main()
{
    int *p = (int*)malloc(sizeof(int) * 1024);
    if( p == nullptr)
    {
        return -1;
    }
    *p = 100;
    free(p);

    try
    {
        int *p1 = new int(1024);
        delete p1;
    }
    catch (const bad_alloc &e)
    {
        1;
    }
    
    


    return 0;
}

