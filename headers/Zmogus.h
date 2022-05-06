#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;

class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    virtual void f() = 0;

public:
    Zmogus();
    ~Zmogus();
    Zmogus(const Zmogus &z);
    void setFirstName(string &name);
    void setFirstName(std::istream &name);
    void setLastName(string &name);
    void setLastName(std::istream &name);
    void setEgz(int mark);

    std::string getFirstName() const;
    std::string getLastName() const;
};
