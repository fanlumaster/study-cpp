#include <iostream>
#include <Windows.h>
#include <WinUser.h>

int main()
{

    while (1)
    {
        Sleep(1000);
        POINT p; // 定义一个POINT变量，用于存储鼠标的坐标
        // GetCursorPos(&p); // 获取鼠标位置
        GetCaretPos(&p); // 获取文本光标位置
        std::cout << "position -> x:" << p.x << ", y:" << p.y << ". " << std::endl;
        }

    return 0;
}