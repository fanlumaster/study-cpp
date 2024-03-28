#include <iostream>

using namespace std;

class str
{
  private:
    char *w;
    int m, len;
    /* char w[5]; */

  public:
    /* str(const char *p, int n, int k) : m(n), len(k) { strcpy_s(w, p); } */
    str(char *p, int n, int k) : w(p), m(n), len(k)
    {
    }
    void move();
    void show();
};

void str::move()
{
    for (int i = 0; i < m; i++)
    {
        char first = *w;
        cout << w[0] << endl;
        for (int j = 1; j < len; j++)
        {
            w[j - 1] = w[j];
        }
        w[len - 1] = first;
    }
}

void str::show()
{
    for (int i = 0; i < len; i++)
    {
        cout << *(w + i) << " ";
    }
}

int main()
{
    char buffer[] = "ACBD";
    /* str c("ABCD", 3, 4); */
    str c(buffer, 3, 4);
    c.move();
    c.show();
    return 0;
}
