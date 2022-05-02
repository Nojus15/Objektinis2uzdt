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
    double vid;
    double med;

    bool checkMark(int n);

public:
    Studentas();
    Studentas(const Studentas &s);
    Studentas &operator=(const Studentas &s);
    ~Studentas();

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