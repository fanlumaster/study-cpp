#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

// test
#include <bitset>

using namespace std;

const int N = 6;
int a[N], ans, aa[N];
char s[N];

/**
 * 点击开关
 * x, y 是开关矩阵中的坐标，其中 x 的取值范围是 [1, 5]，y 的取值范围是 [0, 4]
 */
void toggleSwitch(int x, int y) {
    aa[x] ^= (1 << y);
    if (x != 1) aa[x - 1] ^= (1 << y);
    if (x != 5) aa[x + 1] ^= (1 << y);
    if (y != 0) aa[x] ^= (1 << (y - 1));
    if (y != 4) aa[x] ^= (1 << (y + 1));
}

/**
 * 递推
 * p 是当前的第一行的情况
 */
void recurrence(int p) {
    int k = 0;
    // 把 a 赋值给 aa
    memcpy(aa, a, sizeof(a));
    // 模拟第一行的点击
    for (int i = 0; i < 5; i++) {
        if ((p >> i) & 1) {      // 如果 p 的第 i 位是 1，这里其实无论是 0 还是 1 其实都可以，因为是模拟第一行的点击
            toggleSwitch(1, i);  // 把 aa 中的 (1, i) 这个位置的数字变成 1，其原来是 0
            if (++k >= ans) {    // 因为 ans 后续是可能变小的，即在某一种 p 的情况下会变小，不一定一直保持最初的 21
                return;
            }
        }
    }
    // 第一行确定了之后，那么，下面的 4 行就也随之确定了
    for (int x = 1; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if ((aa[x] >> y) & 1) {      // 如果 aa[x] 的第 y 位是 1
                toggleSwitch(x + 1, y);  // 点击下一行的位置
                if (++k >= ans) {
                    return;
                }
            }
        }
    }

    if (aa[5] == 0) {  // 如果最后一行是全 0 的话
        // cout << "bingo" << endl;
        // for (int i = 1; i < 6; i++) {
        //     cout << bitset<5>(aa[i]) << '\n';
        // }
        // cout << k << '\n';
        // cout << p << '\n';
        // cout << "bingo end" << '\n';
        ans = k;
    }
}

void solve() {
    // 初始化 a 这个数组
    memset(a, 0, sizeof(a));
    // 依次读入字符串，填入到 s 数组中
    for (int i = 1; i <= 5; i++) {
        cin >> (s + 1);
        // 把 s 这个字符串转换成 int 值，然后填入到 a[i] 中去
        for (int j = 1; j <= 5; j++) {
            a[i] = a[i] * 2 + (s[j] - '0');
        }
    }
    // 这里 ans 的初始值就设的稍微大一点，因为四行其实最多可以点击 20 次这个开关
    ans = 21;
    // 对第一行的每一种情况进行遍历
    for (int p = 0; p < (1 << 5); p++) {
        recurrence(p);
    }

    if (ans == 21) {  // 所有的情况走下来，都没有找到更小的 ans
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    freopen("./liyuds_cases/CH0201.in", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
