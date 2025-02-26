#include "mano_lib.h"

void vardoIvedimas(Stud &laik)
{
    cout << "Įveskite studento vardą: ";
    cin >> laik.vardas;
    cout << "Įveskite studento pavardę: ";
    cin >> laik.pavarde;
}

void pazymiuIvedimas(Stud &laik)
{
    bool naujasPazymys = true;
    int pazymys, pasirinkimas;
    cout << "Įveskite studento egzamino rezultatą: ";
    cin >> laik.egz;
    while (naujasPazymys)
    {
        cout << "Įveskite studento namų darbų pažymį: ";
        cin >> pazymys;
        laik.nd.push_back(pazymys);
        cout << "Ar norite įvesti dar vieną pažymį?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pasirinkimas;
        if (pasirinkimas == 2)
            naujasPazymys = false;
    }
}

void vardoGeneravimas(Stud &laik)
{
    string motVardas[] = {"Monika", "Auguste", "Astrida", "Nika", "Liveta", "Juste", "Beatrice", "Egle", "Emile", "Vanesa", "Anastasija", "Gabija", "Migle", "Neda", "Teja", "Vasare"};
    string motPavarde[] = {"Tamelyte", "Tumaite", "Jablonskyte", "Bukolovaite", "Ruskute", "Vaitkeviciute", "Rokaite", "Gurklyte", "Kesaite", "Balsyte", "Fedorenko", "Kameneckaite", "Cincikaite", "Davidaviciute", "Tupinyte", "Milkovaite"};
    string vyrVardas[] = {"Adomas", "Andrius", "Arnas", "Benediktas", "Dominykas", "Emilis", "Gabrielius", "Gustavas", "Ignas", "Julius", "Justas", "Karolis", "Kristijonas", "Kristupas", "Marijus", "Martynas"};
    string vyrPavarde[] = {"Lukosevicius", "Rakauskas", "Matuolis", "Juozapavicius", "Pronskus", "Slabada", "Rutkauskas", "Marcinkevicius", "Volodko", "Truksinas", "Andrulevicius", "Narbutis", "Pocius", "Arifovas", "Kuprys", "Simanavicius"};
    if (rand() % 2 != 0)
    {
        laik.vardas = vyrVardas[rand() % 16];
        laik.pavarde = vyrPavarde[rand() % 16];
    }
    else
    {
        laik.vardas = motVardas[rand() % 16];
        laik.pavarde = motPavarde[rand() % 16];
    }
}

void pazymiuGeneravimas(Stud &laik)
{
    laik.egz = (rand() % 10) + 1;
    for (int i = 0; i < rand() + 1; i++)
    {
        laik.nd.push_back((rand() % 10) + 1);
    }
}

void ivedimas(vector<Stud> &studentai, int &meniuPasirinkimas)
{
    bool naujasStudentas = true;
    int pasirinkimas;
    while (naujasStudentas)
    {
        Stud laik;
        if (meniuPasirinkimas == 1 || meniuPasirinkimas == 2)
            vardoIvedimas(laik);
        if (meniuPasirinkimas == 1)
            pazymiuIvedimas(laik);
        else if (meniuPasirinkimas == 2)
            pazymiuGeneravimas(laik);
        else if (meniuPasirinkimas == 3)
        {
            vardoGeneravimas(laik);
            pazymiuGeneravimas(laik);
        }
        studentai.push_back(laik);
        cout << "Ar norite įvesti dar vieną studentą?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pasirinkimas;
        if (pasirinkimas == 2)
            naujasStudentas = false;
    }
}

double vidurkis(vector<int> nd)
{
    double suma = 0;
    for (int i : nd)
    {
        suma += i;
    }
    return suma / nd.size();
}

double mediana(vector<int> nd)
{
    int dydis;
    sort(nd.begin(), nd.end());
    dydis = nd.size();
    if (dydis % 2 == 0)
        return (nd[dydis / 2] + nd[(dydis / 2) - 1]) / 2;
    else
        return nd[floor(nd.size() / 2)];
}

void isvedimasIFaila(vector<Stud> studentai)
{
    stringstream buferis;
    buferis << setw(12) << left << "Vardas" << setw(16) << "Pavardė" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    buferis << "--------------------------------------------------------------" << endl;
    for (Stud i : studentai)
    {
        buferis << setw(12) << i.vardas;
        buferis << setw(16) << i.pavarde;
        buferis << setw(20) << fixed << setprecision(2) << (vidurkis(i.nd) * 0.4) + (i.egz * 0.6);
        buferis << setw(20) << fixed << setprecision(2) << (mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
    }

    ofstream fout("rez.txt");
    fout << buferis.rdbuf();
    fout.close();
}

void nuskaitymasSuBuferiu(vector<Stud> &studentai, string failoPavadinimas)
{
    vector<string> laik;
    Stud studentas;
    string eilute;
    stringstream buferis;

    ifstream fin(failoPavadinimas);
    buferis << fin.rdbuf();
    fin.close();

    while (buferis)
    {
        if (!buferis.eof())
        {
            getline(buferis, eilute);
            laik.push_back(eilute);
        }
        else
            break;
    }

    studentai.clear();
    int skaicius;
    bool pirmaEilute = true;
    for (string a : laik)
    {
        istringstream is(a);
        if (pirmaEilute == true)
            pirmaEilute = false;
        else
        {
            is >> studentas.vardas >> studentas.pavarde;
            studentas.nd.clear();
            while (is >> skaicius)
            {
                studentas.nd.push_back(skaicius);
            }
            studentas.egz = studentas.nd.back();
            studentas.nd.pop_back();
            studentai.push_back(studentas);
        }
    }
}

void isvedimas(vector<Stud> studentai, int galutinioBaloPasirinkimas)
{
    cout << setw(12) << left << "Vardas";
    cout << setw(15) << "Pavardė";
    if (galutinioBaloPasirinkimas == 1)
        cout << setw(20) << "Galutinis (Vid.)" << endl;
    else if (galutinioBaloPasirinkimas == 2)
        cout << setw(20) << "Galutinis (Med.)" << endl;
    else
    {
        cout << setw(20) << "Galutinis (Vid.)";
        cout << setw(20) << "Galutinis (Med.)" << endl;
    }
    cout << "----------------------------------------" << endl;
    for (Stud i : studentai)
    {
        cout << setw(12) << i.vardas;
        cout << setw(15) << i.pavarde;
        if (galutinioBaloPasirinkimas == 1)
            cout << setw(20) << fixed << setprecision(2) << (vidurkis(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        else if (galutinioBaloPasirinkimas == 2)
            cout << setw(20) << fixed << setprecision(2) << (mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        else
        {
            cout << setw(20) << fixed << setprecision(2) << (vidurkis(i.nd) * 0.4) + (i.egz * 0.6);
            cout << setw(20) << fixed << setprecision(2) << (mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        }
    }
}

bool pagalVarda(Stud &a, Stud &b)
{
    return a.vardas < b.vardas;
}

bool pagalPavarde(Stud &a, Stud &b)
{
    return b.pavarde > a.pavarde;
}

bool pagalVidurki(Stud &a, Stud &b)
{
    return (vidurkis(b.nd) * 0.4) + (b.egz * 0.6) > (vidurkis(a.nd) * 0.4) + (a.egz * 0.6);
}

bool pagalMediana(Stud &a, Stud &b)
{
    return (mediana(b.nd) * 0.4) + (b.egz * 0.6) > (mediana(a.nd) * 0.4) + (a.egz * 0.6);
}

void testas(string failoPavadinimas)
{
    vector<Stud> studentai;
    double vidurkis;
    for (int i = 0; i < 3; i++)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        nuskaitymasSuBuferiu(studentai, failoPavadinimas);
        isvedimasIFaila(studentai);
        auto t2 = std::chrono::high_resolution_clock::now();
        vidurkis += ((t2 - t1) / 1.0s);
    }
    cout << "Vidutinis laikas: " << vidurkis / 3 << " s." << endl;
}

void rusiavimas(vector<Stud> &studentai)
{
    int pasirinkimas;
    cout << "Kaip norėtum surūšiuoti rezultatus?" << endl;
    cout << "1 - pagal vardą" << endl;
    cout << "2 - pagal pavardę" << endl;
    cout << "3 - pagal vidurkį" << endl;
    cout << "4 - pagal medianą" << endl;
    cin >> pasirinkimas;
    if (pasirinkimas == 1)
        sort(studentai.begin(), studentai.end(), pagalVarda);
    if (pasirinkimas == 2)
        sort(studentai.begin(), studentai.end(), pagalPavarde);
    if (pasirinkimas == 3)
        sort(studentai.begin(), studentai.end(), pagalVidurki);
    if (pasirinkimas == 4)
        sort(studentai.begin(), studentai.end(), pagalMediana);
}

string failoPasirinkimas()
{
    system("dir /b *.txt > temp.txt");
    ifstream fin("temp.txt");
    vector<string> failuPavadinimai;
    vector<string> nenorimiFailai = {"rez.txt", "temp.txt"};
    string pavadinimas;
    int failoNumeris;
    while (!fin.eof())
    {
        bool nenorimasFailas = false;
        getline(fin, pavadinimas);
        for (int i = 0; i < nenorimiFailai.size(); i++)
        {
            if (pavadinimas == nenorimiFailai[i])
                nenorimasFailas = true;
        }
        if (nenorimasFailas == false)
            failuPavadinimai.push_back(pavadinimas);
    }
    fin.close();
    system("del temp.txt");
    cout << "Su kuriuo failu norėtumėte testuoti kodą?" << endl;
    for (int i = 1; i < failuPavadinimai.size(); i++)
    {
        cout << i << " - " << failuPavadinimai[i - 1] << endl;
    }
    cin >> failoNumeris;
    return failuPavadinimai[failoNumeris - 1];
}