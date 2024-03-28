#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path dir_path = "C:\\Users\\fanyfull\\Desktop";
    // dir_path = "./rocksdb/examples/ecarray/disk1/test02.cpp";

    for (const auto& entry : fs::directory_iterator(dir_path)) {
        std::cout << entry.path().filename() << std::endl;  // 输出文件名
    }

    return 0;
}
