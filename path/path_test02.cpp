#include <filesystem>
#include <iostream>

int main() {
    // 获取当前文件路径
    std::filesystem::path current_path = std::filesystem::current_path();
    std::cout << "Current path: " << current_path << std::endl;

    // 获取父目录
    std::filesystem::path parent_path = current_path.parent_path();
    std::cout << "Parent path: " << parent_path << std::endl;

    return 0;
}