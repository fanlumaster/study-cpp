/**
 * 要好好审题
 *
 * 另外，在 c++ 中，如果要使用 sqrt 和 pow 等数学函数，
 * 要 include 头文件 <cmath>
 */
#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n)
{
    int attemp = (int)sqrt(n);
    return attemp * attemp == n;
}
bool isRight(int n)
{
    if (!isPerfectSquare(n))
    {
        return false;
    }
    for (int i = 1; i <= 6; i++)
    {
        int tmp = (int)pow(10.0, (double)i);
        if (tmp >= n)
        {
            break;
        }
        if (n % tmp != 0)
        {
            int right = n % tmp;
            int left = (n - right) / tmp;
            if (isPerfectSquare(left) && isPerfectSquare(right))
            {
                return true;
            }
        }
    }
    return false;
}

int a, b;

int main(int argc, char const *argv[])
{
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (isRight(i))
        {
            cout << i << '\n';
        }
    }

    return 0;
}