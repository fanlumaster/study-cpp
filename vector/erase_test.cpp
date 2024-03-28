#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << vec.size() << '\n';

    // 移除前两个元素
    vec.erase(vec.begin(), vec.begin() + 2);

    // 输出移除后的元素和 size
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "size: " << vec.size() << std::endl;

    return 0;
}