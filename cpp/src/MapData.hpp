#ifndef MAPDATA_HPP
#define MAPDATA_HPP

// 定义宏
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 声明类
class point
{
public:
    point(){};
    point(int x_, int y_) : x(x_), y(y_) {}
    point &operator=(const point &other)
    {
        if (this != &other)
        {
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }

    // point &operator+(const point &other)
    // {
    //     return point(this->x + other.x, this->y + other.y);
    // }

    point &operator+=(const point &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    int x;
    int y;
};

#endif