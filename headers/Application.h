#pragma once

#include "Validator.h"
#include "Studentas.h"
#include "Generator.h"
#include "Timer.h"

#include <deque>
#include <list>

using std::deque;
using std::list;

class Application : public Validator
{
private:
    bool genMode;
    int programMode;
    int container_type;
    int strat_type;
    std::chrono::time_point<std::chrono::high_resolution_clock> programStart;
    string file_name;

    Studentas studentai;
    Generator generator;
    Timer programTimer;
    Timer otherTimer;

    bool egz;
    bool paz;
    bool manual;

public:
    Application(/* args */);
    ~Application();
    void run();

private:
    void ivestis(Studentas &temp);

    void bufer_read_students(vector<Studentas> &studentai);
    void bufer_write_students(std::string write_vardas, vector<Studentas> &studentai);

    void bufer_read_students(list<Studentas> &studentai);
    void bufer_write_students(std::string write_vardas, list<Studentas> &studentai);

    void bufer_read_students(deque<Studentas> &studentai);
    void bufer_write_students(std::string write_vardas, deque<Studentas> &studentai);

    void bufer_to_container();

    void genFile(int size, string file_name, int ndCount);
    void containerToFile(string file_name, vector<Studentas> &data);
    void containerToFile(string file_name, list<Studentas> &data);
    void containerToFile(string file_name, deque<Studentas> &data);
    void openFile(std::ifstream &open_f);
    std::string writeFileName();

    void printToFile(string text);

    void sortStudents(vector<Studentas> &kietiakai, vector<Studentas> &vargsai, vector<Studentas> &students);
    void sortStudents(list<Studentas> &kietiakai, list<Studentas> &vargsai, list<Studentas> &students);
    void sortStudents(deque<Studentas> &kietiakai, deque<Studentas> &vargsai, deque<Studentas> &students);

    void sortStudents2(vector<Studentas> &kietiakai, vector<Studentas> &vargsai);
    void sortStudents2(list<Studentas> &kietiakai, list<Studentas> &vargsai);
    void sortStudents2(deque<Studentas> &kietiakai, deque<Studentas> &vargsai);

    void processStrats(vector<Studentas> &studentai, vector<Studentas> &kietiakai, vector<Studentas> &vargsai);
    void processStrats(list<Studentas> &studentai, list<Studentas> &kietiakai, list<Studentas> &vargsai);
    void processStrats(deque<Studentas> &studentai, deque<Studentas> &kietiakai, deque<Studentas> &vargsai);

    void runManualMode();
    void runAutoMode();
};