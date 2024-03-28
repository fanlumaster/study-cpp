#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> chosen;
void calc(int x) {
    // 这里的疑问是，为什么可以保证 chosen.size() == m
    // 这里的 n - x + 1 的意思是从当前这个值到最后的 n 这之间一共有的 item 的数量，
    // 为什么这里会把当前的这个值也算上呢？因为当前这个值其实还没有被加紧 chosen 中去，
    // 以这一层的视角来看，最多是把 x - 1 给添加进 chosen 中去，
    // 当前至多在 chosen 中加入了 x - 1 个元素，这里把 (n - x + 1) 写成 (n - (x - 1)) 可能会更好理解一些
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m) return;
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); i++) printf("%d ", chosen[i]);
        puts("");  // 换行
        return;
    }
    // 注意和上一题的区别，也就是这里的 push 和 pop 的顺序
    calc(x + 1);
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();

    // 这里换成下面的顺序也是可以的
    // chosen.push_back(x);
    // calc(x + 1);
    // chosen.pop_back();
    // calc(x + 1);
}
int main() {
    freopen("./liyuds_cases/CH0302.in", "r", stdin);
    cin >> n >> m;
    calc(1);
}
