// fany
// Ankh => A: 1
// Wedjat => J: 3
// Djed => D: 5
// Scarab => S: 4
// Was => W: 0
// Akhet => K: 2
#define _CRT_SECURE_NO_WARNINGS
// UVa1103 Ancient Messages
// Rujia Liu
// we pad one empty line/column to the top/bottom/left/right border, so color 1 is always "background" white

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

char bin[256][5];

const int maxh = 200 + 5;
const int maxw = 50 * 4 + 5;

int H, W, pic[maxh][maxw], color[maxh][maxw];

char line[maxw];

void decode(char ch, int row, int col) {
    for (int i = 0; i < 4; i++) pic[row][col + i] = bin[ch][i] - '0';
}

// => 左、右、上、下
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// dfs from (row, col) and paint color c

void dfs(int row, int col, int c) {
    color[row][col] = c;           // 这里是对色块的 color 进行染色的操作
    for (int i = 0; i < 4; i++) {  // 左、右、上、下
        int row2 = row + dr[i];
        int col2 = col + dc[i];
        // 四个条件
        // 1、行满足边界条件
        // 2、列满足边界条件
        // 3、当前方向的 pic 值要与原来的相同
        // 4、当前搜索正在处理的色块的 color 要为 0，也就是说，没有被染过色，也就是说，没有被之前的 dfs 处理过
        if (row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == pic[row][col] && color[row2][col2] == 0) dfs(row2, col2, c);  // 在递归进去的时候，不会对 cnt 进行修改
    }
}

vector<set<int>> neighbors;

void check_neighbors(int row, int col) {
    // 左、右、上、下
    for (int i = 0; i < 4; i++) {
        int row2 = row + dr[i];
        int col2 = col + dc[i];
        // 四个条件
        // 1、行满足边界条件
        // 2、列满足边界条件
        // 3、当前方向的 pic 值要与原来的相同
        // 4、当前方向的色块的 color 要不为 1，也就是说，不为最外面的大的 0 连通块
        if (row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == 0 && color[row2][col2] != 1) neighbors[color[row][col]].insert(color[row2][col2]);
    }
}

const char* code = "WAKJSD";

char recognize(int c) {
    int cnt = neighbors[c].size();  // 这个值就是里面的空洞的数量
    return code[cnt];
}

// use this function to print the decoded picture
void print() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) printf("%d", pic[i][j]);
        printf("\n");
    }
}

int main() {
    // 重定向到文件
    freopen("./UVa1103.txt", "r", stdin);

    strcpy(bin['0'], "0000");
    strcpy(bin['1'], "0001");
    strcpy(bin['2'], "0010");
    strcpy(bin['3'], "0011");
    strcpy(bin['4'], "0100");
    strcpy(bin['5'], "0101");
    strcpy(bin['6'], "0110");
    strcpy(bin['7'], "0111");
    strcpy(bin['8'], "1000");
    strcpy(bin['9'], "1001");
    strcpy(bin['a'], "1010");
    strcpy(bin['b'], "1011");
    strcpy(bin['c'], "1100");
    strcpy(bin['d'], "1101");
    strcpy(bin['e'], "1110");
    strcpy(bin['f'], "1111");

    int kase = 0;

    while (scanf("%d%d", &H, &W) == 2 && H) {
        memset(pic, 0, sizeof(pic));
        for (int i = 0; i < H; i++) {
            scanf("%s", line);
            for (int j = 0; j < W; j++) decode(line[j], i + 1, j * 4 + 1);
        }

        H += 2;
        W = W * 4 + 2;
        int cnt = 0;
        vector<int> cc;                   // connected components of 1
        memset(color, 0, sizeof(color));  // color 一开始都是为 0 的
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (!color[i][j]) {                         // 如果 color 没有被染过色，即，之前没有被搜索遍历过
                    dfs(i, j, ++cnt);                       // cnt 会在这里变化
                    if (pic[i][j] == 1) cc.push_back(cnt);  // 如果颜色是 1，那么，这个连通块就是一个符号形状的边界
                }

        // 打印 cc vector
        std::cout << "================cc vector================" << '\n';
        for (auto n : cc) {
            std::cout << n << ' ';
        }
        std::cout << '\n';
        std::cout << "=============cc vector ends==============" << '\n';

        neighbors.clear();  // 清空

        neighbors.resize(cnt + 1);  // 扩展到 cnt + 1 这个尺寸
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (pic[i][j] == 1) check_neighbors(i, j);  // pic 的值为 1，注意，不是 color => check_neighbors

        vector<char> ans;
        for (int i = 0; i < cc.size(); i++) ans.push_back(recognize(cc[i]));
        sort(ans.begin(), ans.end());
        printf("Case %d: ", ++kase);
        for (int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        printf("\n");

        // 打印 pic 数组
        std::cout << "================pic array================" << '\n';
        for (int row = 0; row < H; row++) {
            for (int col = 0; col < W; col++) {
                std::cout << pic[row][col] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "=============pic array ends==============" << '\n';

        // 打印 color 数组
        std::cout << "================color array================" << '\n';
        for (int row = 0; row < H; row++) {
            for (int col = 0; col < W; col++) {
                std::cout << color[row][col] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "=============color array ends==============" << '\n';

        // 打印 neighbors vector
        std::cout << "================neighbors vector================" << '\n';
        for (auto set : neighbors) {
            for (auto n : set) {
                std::cout << n << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "=============neighbors vector ends==============" << '\n';
    }

    return 0;
}
