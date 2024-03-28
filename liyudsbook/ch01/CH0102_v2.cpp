#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

#define ll long long

ll mul_v2(ll a, ll b, ll p) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

typedef unsigned long long ull;

using namespace std;

long long a, b, p;

ull mul(ull a, ull b, ull p) {
    a %= p, b %= p;  // 当a,b一定在0~p之间时，此行不必要
    ull c = (long double)a * b / p;
    // cout << "long double a * b => " << setprecision(numeric_limits<long double>::digits10 + 1) << (long double)a * b << endl;
    // cout << "c => " << c << endl;
    ull x = a * b;
    ull y = c * p;
    // cout << "x => " << x << ", y => " << y << endl;
    // cout << "bin version: x => " << bitset<64>(x) << endl;
    // cout << "             y => " << bitset<64>(y) << endl;
    // long long ans = (long long)(x % p) - (long long)(y % p);
    long long ans = (long long)(x % p) - (long long)(y % p);
    // cout << (long long)(x % p) << endl;
    // cout << (long long)(y % p) << endl;
    // cout << ans << endl;
    if (ans < 0) ans += p;
    return ans;
}

int main() {
    // 重定向到文件
    // freopen("./liyuds_cases/mul1.in", "r", stdin);
    // freopen("./liyuds_cases/mul3.in", "r", stdin);
    // cin >> a >> b >> p;
    // cout << mul(a, b, p) << endl;

    // ll right = (ll)1000000000000000000;
    ll p = (ll)87654321123456788;
    for (ll a = 8765432112345678; a < 87654321123456788; a++) {
        for (ll b = 8765432112345678; b < 87654321123456788; b++) {
            if (mul_v2(a, b, p) != mul(a, b, p)) {
                cout << "a => " << a << ", b => " << b << endl;
                cout << mul_v2(a, b, p) << ", " << mul(a, b, p) << endl;
            }
        }
    }
}

/*
7683280011614083000000000000000000 <= 由下面的数四舍五入
7683280011614082689894832256363369

                                                 0000001001110011100110111110001111010101110011001010101101101001
10111101011010000101000001010101001101100011000100000001001110011100110111110001111010101110011001010101101101001

                                                 0000000000000100110010011001101111010010100111011011110101000000
10111101011010000101000001010101001101100011000100000001001110011100110111110001111010101110011001010101101101000


9223372036854775807
*/