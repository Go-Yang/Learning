#include <iostream>
using namespace std;

/*运算符重载*/
class point
{
public:
    point() : x(0), y(0), z(0) {}
    point(int _x, int _y) : x(_x), y(_y), z(0) {}
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    point operator+(const point &other)
    {
        point tmp;
        tmp.x = this->x + other.x;
        tmp.y = this->y + other.y;
        tmp.z = this->z + other.z;
        return tmp;
    }
    point operator-(const point &other)
    {
        point tmp;
        tmp.x = this->x - other.x;
        tmp.y = this->y - other.y;
        tmp.z = this->z - other.z;
        return tmp;
    }
    void operator=(const point &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }
    void operator+=(const point &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
    }
    void operator-=(const point &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
    }
    int operator*(const point &other)
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }

    void print()
    {
        cout << this << " " << this->x << " " << this->y << " " << this->z << endl;
    }

    int x;
    int y;
    int z;
};
point cross(const point &a, const point &b)
{
    return point(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}
/*运算符重载*/

/*函数重载*/
void add(int a, int b)
{
    cout << "int: " << a + b << endl;
}
void add(double a, double b)
{
    cout << "double: " << a + b << endl;
}
void add(bool a, bool b)
{
    cout << "bool: " << (bool)(a & b) << endl;
}
/*----------*/
class Base {
public:
    void func(int a) {
        cout << "Base::func()" << endl;
    }
};

class Derived : public Base {
public:
    using Base::func;  // 使基类的 func(int) 在子类中可见
    void func(double a) {
        cout << "Derived::func()" << endl;
    }
};
/*函数重载*/

int main()
{
    
    add(false,true);
    Base b;
    Derived d;
    b.func(1);
    b.func(1.0);
    d.func(1);
    d.func(1.0);
    return 0;
}
