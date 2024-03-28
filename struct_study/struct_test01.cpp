#include <iostream>
#include <vector>

struct MyClass {
    std::vector<int>& data;

    // MyClass(std::vector<int> const& data) : data(data) { std::cout << "Constructed with provided data." << std::endl; }
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    MyClass obj{data};

    obj.data.push_back(6);
    std::cout << data.size() << '\n';

    return 0;
}
