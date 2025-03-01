#include "mano_lib.h"
#include "antrastes.h"

void vardoIvedimas(Stud &laik)
{
    while (true)
    {
        try
        {
            cout << "Įveskite studento vardą: ";
            cin >> laik.vardas;
            bool blogasIvedimas = false;
            for (char c : laik.vardas)
            {
                if (!isalpha(c))
                    blogasIvedimas = true;
            }
            if (blogasIvedimas)
            {
                throw "Įvedėte netinkamą simbolį";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    while (true)
    {
        try
        {
            cout << "Įveskite studento pavardę: ";
            cin >> laik.pavarde;
            bool blogasIvedimas = false;
            for (char c : laik.pavarde)
            {
                if (!isalpha(c))
                    blogasIvedimas = true;
            }
            if (blogasIvedimas)
            {
                throw "Įvedėte netinkamą simbolį";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
}

void pazymiuIvedimas(Stud &laik)
{
    bool naujasPazymys = true;
    int pazymys, pasirinkimas;
    while (true)
    {
        try
        {
            cout << "Įveskite studento egzamino rezultatą: ";
            cin >> laik.egz;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (laik.egz < 1 || laik.egz > 10)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    while (naujasPazymys)
    {
        while (true)
        {
            try
            {
                cout << "Įveskite studento namų darbų pažymį: ";
                cin >> pazymys;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if (pazymys < 1 || pazymys > 10)
                    throw "Įvedėte netinkamą skaičių!";
                else
                    break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                continue;
            }
        }
        laik.nd.push_back(pazymys);
        while (true)
        {
            try
            {
                cout << "Ar norite įvesti dar vieną pažymį?" << endl;
                cout << "1 - taip" << endl;
                cout << "2 - ne" << endl;
                cin >> pasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if (pasirinkimas < 1 || pasirinkimas > 2)
                    throw "Įvedėte netinkamą skaičių!";
                else
                    break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                continue;
            }
        }
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
        laik.galutinisSuVidurkiu = (vidurkis(laik.nd) * 0.4) + (laik.egz * 0.6);
        laik.galutinisSuMediana = (mediana(laik.nd) * 0.4) + (laik.egz * 0.6);
        studentai.push_back(laik);
        while (true)
        {
            try
            {
                cout << "Ar norite įvesti dar vieną studentą?" << endl;
                cout << "1 - taip" << endl;
                cout << "2 - ne" << endl;
                cin >> pasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if (pasirinkimas < 1 || pasirinkimas > 2)
                    throw "Įvedėte netinkamą skaičių!";
                else
                    break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                continue;
            }
        }
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

void nuskaitymasSuBuferiu(vector<Stud> &studentai, string failoPavadinimas)
{
    vector<string> laik;
    Stud studentas;
    string eilute;
    stringstream buferis;
    ifstream fin;
    while (true)
    {
        try
        {
            fin.open(failoPavadinimas);
            if (fin.fail())
            {
                throw "Nepavyko atidaryti failo.";
            }
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            failoPavadinimas = failoPasirinkimas("Įveskite kitą failo pavadinimą: ");
            continue;
        }
    }
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
            studentas.galutinisSuVidurkiu = (vidurkis(studentas.nd) * 0.4) + (studentas.egz * 0.6);
            studentas.galutinisSuMediana = (mediana(studentas.nd) * 0.4) + (studentas.egz * 0.6);
            studentai.push_back(studentas);
        }
    }
}

void isvedimas(vector<Stud> studentai, int galutinioBaloPasirinkimas, ostream &isvedimoBudas)
{
    stringstream buferis;
    buferis << setw(12) << left << "Vardas" << setw(16) << "Pavardė";
    if (galutinioBaloPasirinkimas == 1)
        buferis << setw(20) << "Galutinis (Vid.)" << endl;
    else
        buferis << setw(20) << "Galutinis (Med.)" << endl;
    buferis << "--------------------------------------------------------------" << endl;
    for (Stud i : studentai)
    {
        buferis << setw(16) << i.vardas;
        buferis << setw(16) << i.pavarde;
        if (galutinioBaloPasirinkimas == 1)
            buferis << setw(20) << fixed << setprecision(2) << i.galutinisSuVidurkiu << endl;
        else
            buferis << setw(20) << fixed << setprecision(2) << i.galutinisSuMediana << endl;
    }

    isvedimoBudas << buferis.rdbuf();
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
    return b.galutinisSuVidurkiu > a.galutinisSuVidurkiu;
}

bool pagalMediana(Stud &a, Stud &b)
{
    return b.galutinisSuMediana > a.galutinisSuMediana;
}

void testas(string failoPavadinimas)
{
    vector<Stud> studentai;
    double vidurkis;
    for (int i = 0; i < 3; i++)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        nuskaitymasSuBuferiu(studentai, failoPavadinimas);
        ofstream fout("rez.txt");
        isvedimas(studentai, 1, fout);
        fout.close();
        auto t2 = std::chrono::high_resolution_clock::now();
        cout << i + 1 << " testas užtruko: " << (t2 - t1) / 1.0s << " s." << endl;
        vidurkis += ((t2 - t1) / 1.0s);
    }
    cout << "Vidutinis laikas: " << vidurkis / 3 << " s." << endl;
}

int rusiavimoPasirinkimas(){
    int pasirinkimas;
    while (true)
    {
        try
        {
            cout << "Kaip norėtum surūšiuoti rezultatus?" << endl;
            cout << "1 - pagal vardą" << endl;
            cout << "2 - pagal pavardę" << endl;
            cout << "3 - pagal vidurkį" << endl;
            cout << "4 - pagal medianą" << endl;
            cin >> pasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (pasirinkimas < 1 || pasirinkimas > 4)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    return pasirinkimas;
}

void rusiavimas(vector<Stud> &studentai, int pasirinkimas)
{
    if (pasirinkimas == 1)
        sort(studentai.begin(), studentai.end(), pagalVarda);
    if (pasirinkimas == 2)
        sort(studentai.begin(), studentai.end(), pagalPavarde);
    if (pasirinkimas == 3)
        sort(studentai.begin(), studentai.end(), pagalVidurki);
    if (pasirinkimas == 4)
        sort(studentai.begin(), studentai.end(), pagalMediana);
}

string failoPasirinkimas(string klausimas)
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
    cout << klausimas << endl;
    for (int i = 1; i < failuPavadinimai.size(); i++)
    {
        cout << i << " - " << failuPavadinimai[i - 1] << endl;
    }
    while (true)
    {
        try
        {
            cin >> failoNumeris;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (failoNumeris < 1 || failoNumeris > failuPavadinimai.size())
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    return failuPavadinimai[failoNumeris - 1];
}

void failoGeneravimas(int failoIlgis)
{
    std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> pazymiuKiekis(1, 20);
    std::uniform_int_distribution<int> pazymys(1, 10);
    ofstream fout;
    string sugeneruotasFailas = "studentai" + to_string(failoIlgis) + ".txt";
    stringstream buferis;
    buferis << setw(15) << left << "Vardas" << setw(18) << "Pavarde" << setw(10);
    int k = pazymiuKiekis(mt);
    for (int i = 0; i < k; i++)
    {
        buferis << setw(10) << "ND" + to_string(i + 1);
    }
    buferis << setw(10) << "Egz.";
    for (int i = 0; i < failoIlgis; i++)
    {
        buferis << endl;
        buferis << setw(15) << "Vardas" + to_string(i + 1) << setw(18) << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < k + 1; j++)
        {
            buferis << setw(10) << pazymys(mt);
        }
    }
    fout.open(sugeneruotasFailas);
    fout << buferis.str();
    fout.close();
}

int galutinioBaloPasirinkimas()
{
    int pasirinkimas;
    while (true)
    {
        try
        {
            cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
            cout << "1 - vidurkį" << endl;
            cout << "2 - medianą" << endl;
            cin >> pasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (pasirinkimas < 1 || pasirinkimas > 2)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    return pasirinkimas;
}

void isskaidymasIGrupes(vector<Stud> studentai, vector<Stud> &protingi, vector<Stud> &neprotingi, int galutinisBalas)
{
    for (Stud s : studentai)
    {
        if (galutinisBalas == 1)
        {
            if (s.galutinisSuVidurkiu >= 5)
                protingi.push_back(s);
            else
                neprotingi.push_back(s);
        }
        else
        {
            if (s.galutinisSuMediana >= 5)
                protingi.push_back(s);
            else
                neprotingi.push_back(s);
        }
    }
    studentai.clear();
}

void tyrimas(vector<Stud> studentai)
{
    int dydzioPasirinkimas = 1000;
    int tyrimoPasirinkimas, rusPasirinkimas;
    string sugeneruotasFailas;
    while (true)
    {
        try
        {
            cout << "Kuri tyrima nori atlikti?" << endl;
            cout << "1" << endl;
            cout << "2" << endl;
            cin >> tyrimoPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (tyrimoPasirinkimas < 1 || tyrimoPasirinkimas > 2)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    if(tyrimoPasirinkimas==2){
        rusPasirinkimas=rusiavimoPasirinkimas();
    }
    for (int i = 0; i < 5; i++)
    {
        double vid = 0;
        for (int j = 0; j < 3; j++)
        {
            auto pradzia = std::chrono::high_resolution_clock::now();
            if (tyrimoPasirinkimas == 1)
            {
                auto t1 = std::chrono::high_resolution_clock::now();
                failoGeneravimas(dydzioPasirinkimas);
                auto t2 = std::chrono::high_resolution_clock::now();
                cout << dydzioPasirinkimas << " studentu failo sugeneravimas truko " << (t2 - t1) / 1.0s << " " << endl;
            }
            if (tyrimoPasirinkimas == 2)
            {
                vector<Stud> protingi;
                vector<Stud> neprotingi;
                auto t3 = std::chrono::high_resolution_clock::now();
                nuskaitymasSuBuferiu(studentai, "studentai" + to_string(dydzioPasirinkimas) + ".txt");
                auto t4 = std::chrono::high_resolution_clock::now();
                cout << "Failo nuskaitymas truko: " << (t4 - t3) / 1.0s << " s." << endl;
                rusiavimas(studentai, rusPasirinkimas);
                auto t5 = std::chrono::high_resolution_clock::now();
                cout << "Studentu vektoriaus surusiavimas truko: " << (t5 - t4) / 1.0s << " s." << endl;
                isskaidymasIGrupes(studentai, protingi, neprotingi, 1);
                auto t6 = std::chrono::high_resolution_clock::now();
                cout << "Isskaidymas pagal galutini bala truko: " << (t6 - t5) / 1.0s << " s." << endl;
                ofstream fout;
                fout.open("protingi" + to_string(dydzioPasirinkimas) + ".txt");
                isvedimas(protingi, 1, fout);
                fout.close();
                auto t7 = std::chrono::high_resolution_clock::now();
                cout << "Protingu vektoriaus isvedimas i faila truko " << (t7 - t6) / 1.0s << " s." << endl;
                fout.open("neprotingi" + to_string(dydzioPasirinkimas) + ".txt");
                isvedimas(neprotingi, 1, fout);
                fout.close();
                auto t8 = std::chrono::high_resolution_clock::now();
                cout << "Neprotingu vektoriaus isvedimas i faila truko " << (t8 - t7) / 1.0s << " s." << endl;
                cout << "Visas procesas su " << dydzioPasirinkimas << " studentu truko " << (t8 - t3) / 1.0s << " s." << endl;
                cout << endl;
            }
            auto pabaiga = std::chrono::high_resolution_clock::now();
            vid += ((pabaiga - pradzia) / 1.0s);
        }
        cout << "Vidutiniskai tyrimas su " << dydzioPasirinkimas << " studentu uztruko " << vid / 3 << " s." << endl;
        cout << endl;
        dydzioPasirinkimas *= 10;
    }
}