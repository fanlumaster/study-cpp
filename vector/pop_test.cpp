/*
    测试一下 pop 的效果，
    结果：用数组来类比的话，就是把右边的元素给 pop 出去
*/

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> myVec{1, 2, 3};
    myVec.push_back(4);
    for (auto each : myVec) {
        std::cout << each << ' ';
    }
    std::cout << '\n';

    myVec.pop_back();

    for (auto each : myVec) {
        std::cout << each << ' ';
    }
    std::cout << '\n';

    return 0;
}