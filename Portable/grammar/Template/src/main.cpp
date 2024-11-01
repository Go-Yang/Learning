#include <iostream>
#include <string>

using namespace std;

template <typename T>
T const& Max(T  a, T  b)
{
    return a > b ? a : b;
}

int main()
{

    cout<<Max(1,2)<<endl<<Max(0.9,1.9)<<endl;
    return 0;
}
