#include <Windows.h>

#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> generateVec() {
    std::vector<std::vector<std::string>> strVec;
    for (int i = 0; i < 1000; i++) {
        std::vector<std::string> curVec;
        for (int j = 0; j < 1000; j++) {
            curVec.push_back(std::to_string(j));
        }
        strVec.push_back(curVec);
    }
    return strVec;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<std::string>> strVec;

    for (int i = 0; i < 100; i++) {
        strVec = generateVec();
        Sleep(100);
    }

    return 0;
}