#define _CRT_SECURE_NO_WARNINGS
/*
    计算 a * b % p
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long a, b, p;

typedef unsigned long long ull;
ull mul(ull a, ull b, ull p) {
    a %= p, b %= p;  // 当a,b一定在0~p之间时，此行不必要
    ull c = (long double)a * b / p;
    ull x = a * b, y = c * p;
    long long ans = (long long)(x % p) - (long long)(y % p);
    if (ans < 0) ans += p;
    return ans;
}

int main() {
    /*
        a: 8765432112345678
        b: 8765432112953417
        p: 87654321123456788
    */
    // freopen("./liyuds_cases/mul4.in", "r", stdin);
    a = 8765432112345678;
    b = 8765432112953417;
    p = 87654321123456788;
    // cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;  // correct answer is 54345679096057018, while here output is 15009041312430882
}
