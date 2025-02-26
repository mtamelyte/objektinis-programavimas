#include <bits/stdc++.h>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::floor;
using std::ifstream;
using std::istringstream;
using std::left;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;
using std::ws;
using namespace std::literals::chrono_literals;
using std::ofstream;
using std::ostringstream;
using std::runtime_error;

struct Stud
{
    string vardas, pavarde;
    vector<int> nd;
    int egz;
};

void vardoIvedimas(Stud &laik);
void pazymiuIvedimas(Stud &laik);
void vardoGeneravimas(Stud &laik);
void pazymiuGeneravimas(Stud &laik);
void ivedimas(vector<Stud> &studentai, int &meniuPasirinkimas);
double vidurkis(vector<int> nd);
double mediana(vector<int> nd);
void isvedimasIFaila(vector<Stud> studentai);
void nuskaitymasSuBuferiu(vector<Stud> &studentai, string failoPavadinimas);
void isvedimas(vector<Stud> studentai, int galutinioBaloPasirinkimas);
bool pagalVarda(Stud &a, Stud &b);
bool pagalPavarde(Stud &a, Stud &b);
bool pagalVidurki(Stud &a, Stud &b);
bool pagalMediana(Stud &a, Stud &b);
void testas(string failoPavadinimas);
void rusiavimas(vector<Stud> &studentai);