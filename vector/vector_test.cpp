#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    // create vector
    vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    // remove items
    const auto new_end(remove(begin(v), end(v), 2));
    // make it actually shorter
    v.erase(new_end, end(v));
    // print the content
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << '\n';

    int n = 6;
    vector<char> enc(6);

    return 0;
}
