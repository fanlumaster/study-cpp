#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> chosen;  // 被选择的数

void calc(int x) {
    if (x == n + 1) {  // 问题边界
        for (int i = 0; i < chosen.size(); i++) {
            printf("%d ", chosen[i]);
        }
        puts("");
        return;
    }
    //"不选x"分支
    calc(x + 1);  // 求解子问题
    //"选x"分支
    chosen.push_back(x);  // 记录x已被选择
    calc(x + 1);          // 求解子问题
    chosen.pop_back();    // 准备回溯到上一问题之前，还原现场
}

int main() {
    freopen("./liyuds_cases/CH0301.in", "r", stdin);
    cin >> n;
    calc(1);  // 主函数中的调用入口
}
