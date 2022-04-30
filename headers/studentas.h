#pragma once

#include "Validator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::left;
using std::list;
using std::right;
using std::setw;
using std::string;
using std::to_string;
using std::vector;

class Studentas : public Validator
{
private:
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz;
    double vid = 0;
    double med = 0;

    bool checkMark(int n);

public:
    void setFirstName(string name);
    void setFirstName(std::istream &name);
    void setLastName(string name);
    void setLastName(std::istream &name);
    void setEgz(int mark);

    double getMed();
    double getVid();
    double getEgz();
    std::string getFirstName();
    std::string getLastName();

    void enterMarkManually();
    void addMark(int mark);
    int get_popMark();

    void galutinisVid();
    void galutinisMed();
    void calcRez();
};

bool compare(Studentas &a, Studentas &b);
bool isVargsas(Studentas &a);