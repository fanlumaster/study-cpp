/**
 * 另一个结构体在栈上的初始化示例
 */
#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    // 先定义结构体
    Point pointInstance = {10, 20};

    // 获取结构体的指针
    Point *ptr = &pointInstance;

    // 访问并输出结构体成员的值
    std::cout << "x = " << ptr->x << ", y = " << ptr->y << std::endl;

    return 0;
}
