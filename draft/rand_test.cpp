#include <Windows.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void getParityName(char* s, int size) {
    // 获取微秒级别的时间戳
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    std::cout << timestamp.time_since_epoch().count() << '\n';
    // 获取parity文件名
    srand(timestamp.time_since_epoch().count());
    time_t t = time(0);  // 获取当前时间戳
    std::cout << "fany test ==> " << timestamp.time_since_epoch().count() << '\n';
    int max = 100000, min = 0;
    int randnum = (rand() % (max - min + 1)) + min;
    struct tm* local_time = localtime(&t);
    strftime(s, size - 1, "%Y-%m-%d %H:%M:%S", local_time);
    string parityName = s;
    parityName += "_" + to_string(randnum) + ".sst";
    strcpy(s, parityName.c_str());
}

int main(int argc, char** argv) {
    // 按当前时间生成parity_name
    char stime[32];
    getParityName(stime, 32);
    string parity_file_name = stime;
    // Sleep(2000);
    printf("获得的第一个文件名为：%s\n", parity_file_name.c_str());
    getParityName(stime, 32);
    parity_file_name = stime;
    printf("获得的第二个文件名为：%s\n", parity_file_name.c_str());
    return 0;
}
