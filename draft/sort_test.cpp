#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int arr[5]{1, 4, 3, 19, 10};
    std::sort(arr, arr + 5);
    for (auto i = 0; i < 5; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << '\n';

    return 0;
}