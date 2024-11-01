#include <iostream>
using namespace std;


int main()
{
    int b = 10;
    const int a = b;

    const int* p = &a;
    int array[a] = {};

    return 0;
}

