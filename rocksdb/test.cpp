#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void read_cost_txt(string cost_path, double **cost) {
    string buf;
    // start to read cost
    fstream fs_cost;
    fs_cost.open(cost_path, ios::in);
    if (fs_cost.is_open()) {
        while (getline(fs_cost, buf)) {
            char src = buf[0];
            char des = buf[2];
            printf("the 141 buffer is %s\n", buf.c_str());
            printf("the 141 src is %c\n", src);
            printf("the 141 des is %c\n", des);
            string tmp = buf;
            tmp = tmp.substr(4, tmp.length() - 4);
            printf("the 141 tmp is %s\n", tmp.c_str());
            // cost[inverse_mapping[src]][inverse_mapping[des]] = stod(tmp.c_str());
        }
    } else {
        printf("open cost_path %s error!\n", cost_path.c_str());
    }
    fs_cost.close();
}