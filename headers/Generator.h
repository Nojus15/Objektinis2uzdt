#pragma once
// +
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <string>
#include "Timer.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::mt19937;
using std::setw;
using std::string;
using std::to_string;

class Generator
{
private:
    std::string file_name;
    int studCount;
    int ndCount;
    Timer genTimer;

public:
    Generator();
    ~Generator();
    void set_file_name(std::string name);
    void set_stud_count(int amount);
    void set_nd_count(int amount);

    int generateRandomMark();
    void genFile();

    std::stringstream genStudentStringStream(int ndCount);
    int randomInt(int from, int to);
    std::string randFirstName();
    std::string randLastName();
};