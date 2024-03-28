#include <iostream>
#include <boost/array.hpp>

int main()
{
    boost::array<int, 10> arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    for (int i = 0; i < 10; i++)
    {
        std::cout << "fany rank is : " << arr[i] << "*" << '\n';
    }

    return 0;
}