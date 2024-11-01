#include <iostream>
#include <memory>

using namespace std;

shared_ptr<int> p_int;
shared_ptr<int> p_int1;
shared_ptr<int> p_int2;
shared_ptr<int> p_int3;
shared_ptr<int> p_int4;
int val = 100;

int main()
{
    p_int = make_shared<int>(val);
    cout << "shared_ptr count: "<< p_int.use_count()<< endl;
    p_int1 = p_int;
    cout << "shared_ptr count: "<< p_int.use_count()<< endl;
    p_int1.reset(); // 正确释放 shared_ptr
    cout << "shared_ptr count: "<< p_int.use_count()<< endl;
    p_int2 = p_int;
    cout << "shared_ptr count: "<< p_int.use_count()<< endl;

    return 0;
}
