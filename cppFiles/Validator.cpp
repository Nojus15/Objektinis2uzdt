#include "../headers/Validator.h"

Validator::Validator() {}
Validator::~Validator() {}
int Validator::enterValidInt()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.good())
            return n;
        else
        {
            cout << "Ne numeris" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

int Validator::validMode(int from, int to)
{
    while (true)
    {
        int mode = enterValidInt();
        for (int i = from; i <= to; i++)
            if (mode == i)
                return mode;
        cout << "Blogas skaicius" << endl;
    }
}
bool Validator::checkMark(int n)
{
    if (n > 0 && n <= 10)
        return true;
    cout << "Netinkamas skaicius" << endl;
    return false;
}
