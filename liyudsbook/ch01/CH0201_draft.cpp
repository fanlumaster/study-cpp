#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    char s[7];
    cin >> (s + 1);
    for (int i = 0; i < 6; i++) {
        cout << s[i];
    }
    return 0;
}