/**
 * 贪心，我只是按照势来理解，并没有很严谨的证明
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 108;

bool comp(int x, int y)
{
    return x > y;
}

int main(int argc, char const *argv[])
{
    int n, m;
    int numsA[maxn];
    int numsB[maxn];
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> numsA[i];
            numsB[i] = numsA[i];
        }
        m = n;
        if (n == 1)
            return 0;
        sort(numsA, numsA + n, comp);
        sort(numsB, numsB + m);
        while (n >= 2)
        {
            numsA[n - 2] = numsA[n - 2] * numsA[n - 1] + 1;
            n--;
            sort(numsA, numsA + n, comp);
        }
        while (m >= 2)
        {
            numsB[m - 2] = numsB[m - 2] * numsB[m - 1] + 1;
            m--;
            sort(numsB, numsB + m);
        }
        cout << numsA[0] - numsB[0] << '\n';
    }

    return 0;
}