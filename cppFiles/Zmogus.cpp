#include "../headers/Zmogus.h"

void Zmogus::setFirstName(string &name)
{
    this->vardas = name;
}
void Zmogus::setFirstName(std::istream &name)
{
    name >> this->vardas;
}
void Zmogus::setLastName(string &name)
{
    this->pavarde = name;
}
void Zmogus::setLastName(std::istream &name)
{
    name >> this->pavarde;
}
std::string Zmogus::getFirstName() const { return vardas; }
std::string Zmogus::getLastName() const { return pavarde; }
Zmogus::Zmogus() : vardas(""), pavarde("") {}
Zmogus::~Zmogus() {}