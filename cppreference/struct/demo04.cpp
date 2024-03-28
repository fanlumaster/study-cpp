/**
 * 结构体在堆上的初始化，可以直接初始化一个指针
 */
#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    // 直接初始化 Point 结构体的指针
    Point *ptr = new Point{10, 20};

    // 访问并输出结构体成员的值
    std::cout << "x = " << ptr->x << ", y = " << ptr->y << std::endl;

    // 记得释放内存
    delete ptr;

    return 0;
}
