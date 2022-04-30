#pragma once

#include "Validator.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
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