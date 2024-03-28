#include <iostream>

using namespace std;

class animal
{
  public:
    void eat()
    {
        cout << "animal eat" << endl;
    }
    void sleep()
    {
        cout << "animal sleep" << endl;
    }
    virtual void breath()
    {
        cout << "animal breath" << endl;
    }
};

class fish : public animal
{
  public:
    void breath()
    {
        cout << "fish bubble" << endl;
    }
};

void fn(animal *pAn)
{
    pAn->breath();
}

int main(int argc, char *argv[])
{
    animal *pAn;
    fish fh;
    pAn = &fh;
    fn(pAn);

    return 0;
}
