#include <iostream>
using namespace std;

class meta 
{
public:
    virtual int getId() = 0;
    virtual int getNature() = 0;
    meta(int _nature, int _id) : nature(_nature), id(_id) {}
protected:
    int nature; // 属性
    int id;     // id
};

class Map : public meta
{
public:
    Map(int _nature, int _id, int _width, int _height) : meta(_nature, _id), width(_width), height(_height) {
        this->data = (uint8_t*)malloc(_width * _height * sizeof(uint8_t));
    }
    ~Map() {
        free(this->data);
    }
    int getId() override {
        return this->id;
    }
    int getNature() override {
        return this->nature;
    }
    virtual void getinfo() const {
        cout << "Base Map class" << endl;
    }

protected:
    int width;
    int height;
private:
    uint8_t* data;
};

class HomeMap : public Map
{
public:
    HomeMap(int _nature, int _id, int _width, int _height)
        : Map(_nature, _id, _width, _height) {}
    void getinfo() const override {
        cout << "HomeMap class" << endl;
    }
};

class SchoolMap : public Map
{
public:
    SchoolMap(int _nature, int _id, int _width, int _height)
        : Map(_nature, _id, _width, _height) {}
    void getinfo() const  {
        cout << "SchoolMap class" << endl;
    }
};

int main()
{
    // 创建 Map 对象需要提供参数
    Map* Bp = new SchoolMap(1, 1, 100, 100);
    Bp->getinfo();
    delete Bp; // 删除对象，释放内存


    return 0;
}
