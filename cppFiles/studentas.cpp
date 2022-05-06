#include "../headers/Studentas.h"

void Studentas::galutinisVid()
{
    double sum = 0;
    for (auto &el : paz)
        sum += el;

    if (paz.size() != 0)
        vid = sum / (paz.size() * 1.0) * 0.4 + egz * 0.6;
    else
        vid = egz * 0.6;
}
void Studentas::galutinisMed()
{
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0 && paz.size() != 0)
    {
        med = (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) * 1.0 / 2;
    }
    else if (paz.size() % 2 != 0 && paz.size() != 0)
    {
        med = paz[paz.size() / 2] * 0.4 + egz * 0.6;
    }
    else if (paz.size() == 0)
    {
        cout << "no marks" << endl;
        med = egz * 0.6;
    }
}
void Studentas::calcRez()
{
    galutinisVid();
    galutinisMed();
}

void Studentas::enterMarkManually()
{
    cout << "Veskite pazymius. Baige vedima iveskite 0" << endl;

    int t;
    while (true)
    {
        t = enterValidInt();
        if (t == 0)
            break;
        else if (checkMark(t))
            paz.push_back(t);
    }
}
bool Studentas::checkMark(int n)
{
    if (n > 0 && n <= 10)
        return true;
    else
    {
        cout << "Blogas pazymys" << endl;
        return false;
    }
}
void Studentas::addMark(int mark)
{
    paz.push_back(mark);
}
int Studentas::get_popMark()
{
    int t = paz.back();
    paz.pop_back();
    return t;
}
void Studentas::setFirstName(string name)
{
    vardas = name;
}
void Studentas::setFirstName(std::istream &name)
{
    name >> vardas;
}
void Studentas::setLastName(string name)
{
    pavarde = name;
}
void Studentas::setLastName(std::istream &name)
{
    name >> pavarde;
}
void Studentas::setEgz(int mark)
{
    egz = mark;
}
double Studentas::getMed() { return med; }
double Studentas::getVid() { return vid; }
double Studentas::getEgz() { return egz; }
std::string Studentas::getFirstName() { return vardas; }
std::string Studentas::getLastName() { return pavarde; }

bool compare(Studentas &a, Studentas &b)
{
    return a.getFirstName() < b.getFirstName();
}
bool isVargsas(Studentas &a)
{
    if (a.getMed() < 5 || a.getVid() < 5)
        return true;
    return false;
}
Studentas::Studentas() : vid(0), med(0) {}
Studentas::Studentas(const Studentas &s)
{
    this->vardas = s.vardas;
    this->pavarde = s.pavarde;
    this->paz.reserve(s.paz.size());
    this->paz.resize(s.paz.size());
    for (int i = 0; i < s.paz.size(); i++)
        this->paz.at(i) = s.paz[i];

    this->egz = s.egz;
    this->vid = s.vid;
    this->med = s.med;
}
Studentas &Studentas::operator=(const Studentas &s)
{
    if (&s == this)
        return *this;
    vardas = s.vardas;
    pavarde = s.pavarde;
    this->paz.reserve(s.paz.size());
    this->paz.resize(s.paz.size());
    for (int i = 0; i < s.paz.size(); i++)
        paz[i] = s.paz[i];
    egz = s.egz;
    vid = s.vid;
    med = s.med;
    return *this;
}
Studentas::~Studentas()
{
    paz.clear();
}
