#include "../headers/Application.h"

std::string Application::writeFileName()
{
    string file_name = "";
    cin.ignore();
    getline(cin, file_name);
    if (!file_name.empty())
        file_name += ".txt";
    return file_name;
}
void Application::run()
{
    cout << "Ar norite generuoti failus? Jei taip, iveskite 1, jei ne - 0" << endl;
    bool gen = validMode(0, 1);
    if (gen)
    {
        Generator fileGen;

        cout << "Koks turetu buti failo pavadinimas?(studentai.txt by default): ";
        fileGen.set_file_name(writeFileName());
        cout << "Kiek generuoti studentu?" << endl;
        fileGen.set_stud_count(enterValidInt());
        cout << "Kiek generuoti namu darbu?" << endl;
        fileGen.set_nd_count(enterValidInt());

        fileGen.genFile();
        return;
    }

    cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
    manual = validMode(0, 1);

    if (!manual)
        runAutoMode();
    else
        runManualMode();
}

void Application::ivestis(Studentas &temp)
{
    cout << "Iveskite varda: ";
    temp.setFirstName(cin);
    cout << "Iveskite pavarde: ";
    temp.setLastName(cin);

    if (egz)
    {
        cout << "Iveskite egzamino ivertinima: ";
        while (true)
        {
            int egz = Validator::enterValidInt();
            if (Validator::checkMark(egz))
            {
                temp.setEgz(egz);
                break;
            }
        }
    }
    else
        temp.setEgz(generator.randomInt(1, 10));

    ////////// pazymiu vedimas ///////////
    if (paz)
        temp.enterMarkManually();
    else
    {
        cout << "Jei norite generuoti pazymi iveskite 1, jei norite baigti iveskite 0" << endl;
        while (true)
        {
            int run = validMode(0, 1);
            if (run)
            {
                temp.addMark(generator.randomInt(1, 10));
            }
            else
                break;
        }
    }
    cout << "pazymiai suvesti" << endl;
}

void Application::bufer_read_students(vector<Studentas> &studentai)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    programTimer.Stop();
    openFile(open_f);
    programTimer.Continue();
    otherTimer.Start();
    my_buffer << open_f.rdbuf();

    open_f.close();
    std::getline(my_buffer, line);

    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        Studentas t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addMark(mark);
        }
        t.setEgz(t.get_popMark());
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << otherTimer.Stop_Return() << " s" << endl;
}
void Application::bufer_read_students(list<Studentas> &studentai)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    programTimer.Stop();
    openFile(open_f);
    programTimer.Continue();
    otherTimer.Start();
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::getline(my_buffer, line);

    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        Studentas t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addMark(mark);
        }
        t.setEgz(t.get_popMark());
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << otherTimer.Stop_Return() << " s" << endl;
}
void Application::bufer_read_students(deque<Studentas> &studentai)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    programTimer.Stop();
    openFile(open_f);
    programTimer.Continue();
    otherTimer.Start();
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::getline(my_buffer, line);

    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        Studentas t;
        std::istringstream lineStream(line);
        t.setFirstName(lineStream);
        t.setLastName(lineStream);
        int mark;
        while (lineStream >> mark)
        {
            t.addMark(mark);
        }
        t.setEgz(t.get_popMark());
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << otherTimer.Stop_Return() << " s" << endl;
}

void Application::bufer_write_students(std::string write_vardas, vector<Studentas> &studentai)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    for (auto &stud : studentai)
    {
        outputas << left << setw(20) << stud.getFirstName();
        outputas << left << setw(20) << stud.getLastName();
        outputas << left << setw(20) << stud.getVid();
        outputas << left << setw(20) << stud.getMed();
        outputas << endl;
    }
    studentai.clear();

    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void Application::bufer_write_students(std::string write_vardas, list<Studentas> &studentai)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    for (auto &stud : studentai)
    {
        outputas << left << setw(20) << stud.getFirstName();
        outputas << left << setw(20) << stud.getLastName();
        outputas << left << setw(20) << stud.getVid();
        outputas << left << setw(20) << stud.getMed();
        outputas << endl;
    }
    studentai.clear();

    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void Application::bufer_write_students(std::string write_vardas, deque<Studentas> &studentai)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    for (auto &stud : studentai)
    {
        outputas << left << setw(20) << stud.getFirstName();
        outputas << left << setw(20) << stud.getLastName();
        outputas << left << setw(20) << stud.getVid();
        outputas << left << setw(20) << stud.getMed();
        outputas << endl;
    }
    studentai.clear();

    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void Application::containerToFile(string file_name, vector<Studentas> &data)
{
    std::stringstream out;
    out << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Vid." << left << setw(20) << "Med." << endl;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.getFirstName();
        out << left << setw(20) << stud.getLastName();
        out << left << setw(20) << stud.getVid();
        out << left << setw(20) << stud.getMed();
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void Application::containerToFile(string file_name, list<Studentas> &data)
{
    std::stringstream out;
    out << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Vid." << left << setw(20) << "Med." << endl;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.getFirstName();
        out << left << setw(20) << stud.getLastName();
        out << left << setw(20) << stud.getVid();
        out << left << setw(20) << stud.getMed();
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void Application::containerToFile(string file_name, deque<Studentas> &data)
{
    std::stringstream out;
    out << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Vid." << left << setw(20) << "Med." << endl;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.getFirstName();
        out << left << setw(20) << stud.getLastName();
        out << left << setw(20) << stud.getVid();
        out << left << setw(20) << stud.getMed();
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void Application::openFile(std::ifstream &open_f)
{
    bool error = true;
    cin.ignore();
    while (error)
    {
        cout << "Iveskite failo pavadinima(numatysis pavadinimas: studentai.txt): ";
        string file_name;
        getline(cin, file_name);

        if (file_name.empty())
            file_name = "studentai.txt";
        try
        {
            open_f.open(file_name);
            if (open_f.fail())
                throw std::invalid_argument("Klaida! Neteisingas failo pavadinimas.");
            error = false;
        }
        catch (const std::invalid_argument &e)
        {
            cout << e.what() << std::endl;
        }
    }
}

Application::Application() {}
Application::~Application() {}
void Application::sortStudents(vector<Studentas> &kietiakai, vector<Studentas> &vargsai, vector<Studentas> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.getVid() < 5)
            vargsai.push_back(stud);
        else
            kietiakai.push_back(stud);
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void Application::sortStudents(list<Studentas> &kietiakai, list<Studentas> &vargsai, list<Studentas> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.getVid() < 5)
            vargsai.push_back(stud);
        else
            kietiakai.push_back(stud);
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void Application::sortStudents(deque<Studentas> &kietiakai, deque<Studentas> &vargsai, deque<Studentas> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.getVid() < 5)
            vargsai.push_back(stud);
        else
            kietiakai.push_back(stud);
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}

void Application::sortStudents2(vector<Studentas> &kietiakai, vector<Studentas> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}

void Application::sortStudents2(list<Studentas> &kietiakai, list<Studentas> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void Application::sortStudents2(deque<Studentas> &kietiakai, deque<Studentas> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void Application::runAutoMode()
{
    cout << "Pasirinkite konteinerio tipa: 1 - vector, 2 - list, 3 - deque" << endl;
    container_type = validMode(1, 3);
    cout << "Kokia strategija norite naudoti? Jei taupyti laika iveskite 1 (1 strategija), jei taupyti atminti iveskite 2 (2 strategija)." << endl;
    strat_type = validMode(1, 2);

    if (container_type == 1)
    {
        vector<Studentas> studentai;
        vector<Studentas> kietiakai;
        vector<Studentas> vargsai;
        programTimer.Start();
        processStrats(studentai, kietiakai, vargsai);

        std::sort(kietiakai.begin(), kietiakai.end(), [](Studentas &a, Studentas &b)
                  { return a.getFirstName() < b.getFirstName(); });
        std::sort(vargsai.begin(), vargsai.end(), [](Studentas &a, Studentas &b)
                  { return a.getFirstName() < b.getFirstName(); });

        otherTimer.Start();
        containerToFile("kietiakai.txt", kietiakai);
        containerToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << otherTimer.Stop_Return() << endl;
    }
    else if (container_type == 2)
    {
        list<Studentas> studentai;
        list<Studentas> kietiakai;
        list<Studentas> vargsai;

        programTimer.Start();
        processStrats(studentai, kietiakai, vargsai);

        kietiakai.sort(compare);
        vargsai.sort(compare);

        otherTimer.Start();
        containerToFile("kietiakai.txt", kietiakai);
        containerToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << otherTimer.Stop_Return() << endl;
    }
    else if (container_type == 3)
    {
        deque<Studentas> studentai;
        deque<Studentas> kietiakai;
        deque<Studentas> vargsai;

        programTimer.Start();
        processStrats(studentai, kietiakai, vargsai);

        std::sort(kietiakai.begin(), kietiakai.end(), [](Studentas &a, Studentas &b)
                  { return a.getFirstName() < b.getLastName(); });
        std::sort(vargsai.begin(), vargsai.end(), [](Studentas &a, Studentas &b)
                  { return a.getFirstName() < b.getLastName(); });

        otherTimer.Start();
        containerToFile("kietiakai.txt", kietiakai);
        containerToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << otherTimer.Stop_Return() << endl;
    }
    cout << "Visos programos veikimo laikas: " << programTimer.Stop_Return() << " s" << endl;
    cout << "-------------------------" << endl;
}

void Application::runManualMode()
{
    otherTimer.Start();
    vector<Studentas> studentai;
    cout << "Jei norite egzamino rezultata ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
    egz = validMode(0, 1);
    cout << "Jei norite pazymius ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
    paz = validMode(0, 1);

    while (true)
    {
        cout << "Jei norite ivesti studenta spauskite 1, jei norite baigti spauskite 0" << endl;
        bool run = validMode(0, 1);
        if (!run)
            break;
        else
        {
            Studentas temp;
            ivestis(temp);
            studentai.push_back(temp);
        }
    }
    for (auto &stud : studentai)
        stud.calcRez();

    std::sort(studentai.begin(), studentai.end(), [](Studentas &a, Studentas &b)
              { return a.getFirstName() < b.getLastName(); });

    bufer_write_students("rez.txt", studentai);
    cout << "Visos programos veikimo laikas: " << otherTimer.Stop_Return() << " s" << endl;
    cout << "-------------------------" << endl;
}

void Application::processStrats(vector<Studentas> &studentai, vector<Studentas> &kietiakai, vector<Studentas> &vargsai)
{
    if (strat_type == 1)
    {
        bufer_read_students(studentai);
        for (auto &el : studentai)
            el.calcRez();
        sortStudents(kietiakai, vargsai, studentai);
    }
    else if (strat_type == 2)
    {
        bufer_read_students(kietiakai);
        for (auto &el : kietiakai)
            el.calcRez();
        sortStudents2(kietiakai, vargsai);
    }
}
void Application::processStrats(list<Studentas> &studentai, list<Studentas> &kietiakai, list<Studentas> &vargsai)
{
    if (strat_type == 1)
    {
        bufer_read_students(studentai);
        for (auto &el : studentai)
            el.calcRez();
        sortStudents(kietiakai, vargsai, studentai);
    }
    else if (strat_type == 2)
    {
        bufer_read_students(kietiakai);
        for (auto &el : kietiakai)
            el.calcRez();
        sortStudents2(kietiakai, vargsai);
    }
}
void Application::processStrats(deque<Studentas> &studentai, deque<Studentas> &kietiakai, deque<Studentas> &vargsai)
{
    if (strat_type == 1)
    {
        bufer_read_students(studentai);
        for (auto &el : studentai)
            el.calcRez();
        sortStudents(kietiakai, vargsai, studentai);
    }
    else if (strat_type == 2)
    {
        bufer_read_students(kietiakai);
        for (auto &el : kietiakai)
            el.calcRez();
        sortStudents2(kietiakai, vargsai);
    }
}