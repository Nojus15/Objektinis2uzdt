#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

class Validator
{
private:
    /* data */
public:
    Validator();
    ~Validator();
    int validMode(int from, int to);
    int enterValidInt();
    bool checkMark(int n);
};
