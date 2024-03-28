/**
 * 输入：
 * **********
 * oo********
 * o*o*******
 * o**o******
 * o***o*****
 * o****o****
 * o****o****
 * 输出：
 * 5
 *
 * 输入：
 * *o**o***o***
 * *o***o**o***
 * 输出：
 * 1
 *
 */
#include <iostream>

using namespace std;

string a, b;

int main(int argc, char const *argv[])
{
    cin >> a >> b;
    // a = "*o**o***o***";
    // b = "*o***o**o***";
    // a = "**********";
    // b = "o****o****";
    int cnt = 0;
    bool flag = 0;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i] && flag == 1)
        {
            cnt++;
        }
        if (a[i] != b[i])
        {
            if (flag == 0)
            {
                cnt++;
            }
            flag = !flag;
        }
    }
    cout << cnt;

    return 0;
}