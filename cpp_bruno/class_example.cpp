#include <iostream>

class X
{
private:
    int m;

public:
    // m{i} 这是 m 自己来做初始化了
    X(int i = 0) : m{i} {}

    // 成员函数
    int mf(int i)
    {
        int old = m;
        m = i;
        return old;
    }
};

class Y
{
private:
    int m;
    double n;

public:
    // m{i} 这是 m 自己来做初始化了
    Y(int i = 0, double j = 12.0) : m{i}, n{j} {}

    // 成员函数
    int mf(int i)
    {
        int old = m;
        m = i;
        return old;
    }
};

X var{7};

void user(X var, X *ptr)
{
    int x = var.mf(8);
    int y = ptr->mf(9);
    x = var.mf(8);
    y = ptr->mf(9);
    std::cout << x << ' ' << y << '\n';
}

int main(int argc, char const *argv[])
{
    user(var, &var);
    return 0;
}
