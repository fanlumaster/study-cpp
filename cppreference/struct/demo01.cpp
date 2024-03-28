// https://en.cppreference.com/w/cpp/keyword/struct
#include <iostream>

struct Foo;

struct Bar
{
    int i;

    Bar(int i) : i(i + i)
    {
    }
};

enum struct Pub
{
    b,
    d,
    p,
    q,
};

int main(int argc, char *argv[])
{
    Bar bar(1);
    struct Bar bar2(2);

    std::cout << bar.i << '\n';
    std::cout << bar2.i << '\n';

    return 0;
}
