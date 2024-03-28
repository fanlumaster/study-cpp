#include <iostream>
#include <map>
#include <string>
#include <vector>

class stripe {
   public:
    stripe() : enc_matrix(n, ' '){};
    bool is_ec = false;
    int n = 6, k = 4;
    int dataNum = 4;
    std::multimap<std::string, int> data_map = {};
    std::string parity_path[2] = {" ", " "};

    // 编码矩阵
    std::vector<char> enc_matrix;
};

int main(int argc, char const *argv[]) {
    std::cout << "test"
              << "\n";
    return 0;
}
