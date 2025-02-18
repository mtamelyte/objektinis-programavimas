#include "mano_lib.h"

void VardoIvedimas(Stud &laik)
{
    cout << "Įveskite studento vardą: ";
    cin >> laik.var;
    cout << "Įveskite studento pavardę: ";
    cin >> laik.pav;
}

void PazymiuIvedimas(Stud &laik)
{
    bool npaz = true;
    int paz, pas;
    cout << "Įveskite studento egzamino rezultatą: ";
    cin >> laik.egz;
    while (npaz)
    {
        cout << "Įveskite studento namų darbų pažymį: ";
        cin >> paz;
        laik.nd.push_back(paz);
        cout << "Ar norite įvesti dar vieną pažymį?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pas;
        if (pas == 2)
            npaz = false;
    }
}

void VardoGeneravimas(Stud &laik)
{
    string m_vardas[] = {"Monika", "Auguste", "Astrida", "Nika", "Liveta", "Juste", "Beatrice", "Egle", "Emile", "Vanesa", "Anastasija", "Gabija", "Migle", "Neda", "Teja", "Vasare"};
    string m_pav[] = {"Tamelyte", "Tumaite", "Jablonskyte", "Bukolovaite", "Ruskute", "Vaitkeviciute", "Rokaite", "Gurklyte", "Kesaite", "Balsyte", "Fedorenko", "Kameneckaite", "Cincikaite", "Davidaviciute", "Tupinyte", "Milkovaite"};
    string v_vardas[] = {"Adomas", "Andrius", "Arnas", "Benediktas", "Dominykas", "Emilis", "Gabrielius", "Gustavas", "Ignas", "Julius", "Justas", "Karolis", "Kristijonas", "Kristupas", "Marijus", "Martynas"};
    string v_pav[] = {"Lukosevicius", "Rakauskas", "Matuolis", "Juozapavicius", "Pronskus", "Slabada", "Rutkauskas", "Marcinkevicius", "Volodko", "Truksinas", "Andrulevicius", "Narbutis", "Pocius", "Arifovas", "Kuprys", "Simanavicius"};
    if (rand() % 2 != 0)
    {
        laik.var = v_vardas[rand() % 16];
        laik.pav = v_pav[rand() % 16];
    }
    else
    {
        laik.var = m_vardas[rand() % 16];
        laik.pav = m_pav[rand() % 16];
    }
}

void PazGeneravimas(Stud &laik)
{
    laik.egz = (rand() % 10) + 1;
    for (int i = 0; i < rand() + 1; i++)
    {
        laik.nd.push_back((rand() % 10) + 1);
    }
}

void Ivedimas(vector<Stud> &s, int &p)
{
    bool nstud = true;
    int pas;
    while (nstud)
    {
        Stud laik;
        if (p == 1 || p == 2)
            VardoIvedimas(laik);
        if (p == 1)
            PazymiuIvedimas(laik);
        else if (p == 2)
            PazGeneravimas(laik);
        else if (p == 3)
        {
            VardoGeneravimas(laik);
            PazGeneravimas(laik);
        }
        s.push_back(laik);
        cout << "Ar norite įvesti dar vieną studentą?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pas;
        if (pas == 2)
            nstud = false;
    }
}

void Nuskaitymas(vector<Stud> & s)
{
    ifstream fin("kursiokai.txt");
    Stud laik;
    int sk;
    while (!fin.eof())
    {
        fin >> ws;
        fin >> laik.var >> laik.pav;
        string pazymiai;
        getline(fin, pazymiai);
        istringstream is(pazymiai);
        while (is >> sk)
        {
            {
                laik.nd.push_back(sk);
            }
        }
        laik.egz=laik.nd.back();
        laik.nd.pop_back();
        s.push_back(laik);
    }
}

double Vidurkis(vector<int> nd)
{
    double sum = 0;
    for (int i : nd)
    {
        sum += i;
    }
    return sum / nd.size();
}

double Mediana(vector<int> nd)
{
    int dydis;
    sort(nd.begin(), nd.end());
    dydis = nd.size();
    if (dydis % 2 == 0)
        return (nd[dydis / 2] + nd[(dydis / 2) - 1]) / 2;
    else
        return nd[floor(nd.size() / 2)];
}

void Isvedimas(vector<Stud> s, int p, int k)
{
    cout << setw(12) << left << "Pavardė";
    cout << setw(16) << "Vardas";
    if (k == 1)
        cout << setw(16) << "Galutinis (Vid.)" << endl;
    else if (k == 2)
        cout << setw(16) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------" << endl;
    for (Stud i : s)
    {
        cout << setw(15) << i.pav;
        cout << setw(12) << i.var;
        if (k == 1)
            cout << setw(16) << fixed << setprecision(2) << (Vidurkis(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        else if (k == 2)
            cout << setw(16) << fixed << setprecision(2) << (Mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
    }
}

bool PagalVarda(Stud & a, Stud & b)
{
    return a.var<b.var;
}

bool PagalPavarde(Stud & a, Stud & b)
{
    return b.pav>a.pav;
}

bool PagalVidurki(Stud & a, Stud & b)
{
    return (Vidurkis(b.nd) * 0.4) + (b.egz * 0.6)>(Vidurkis(a.nd) * 0.4) + (a.egz * 0.6);
}

bool PagalMediana(Stud & a, Stud & b)
{
    return (Mediana(b.nd) * 0.4) + (b.egz * 0.6)>(Mediana(a.nd) * 0.4) + (a.egz * 0.6);
}

void NuskIsvedimas(vector<Stud> s)
{
    cout << setw(12) << left << "Vardas";
    cout << setw(16) << "Pavardė";
        cout << setw(20) << "Galutinis (Vid.)";
        cout << setw(20) << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (Stud i : s)
    {
        cout << setw(12) << i.var;
        cout << setw(16) << i.pav;
            cout << setw(20) << fixed << setprecision(2) << (Vidurkis(i.nd) * 0.4) + (i.egz * 0.6);
            cout << setw(20) << fixed << setprecision(2) << (Mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
    }
}

int main()
{
    srand(time(NULL));
    int k, p;
    vector<Stud> studentai;
    cout << "Ką norėtum daryti?" << endl;
    cout << "1 - Suvesti duomenis ranka" << endl;
    cout << "2 - Sugeneruoti pažymius" << endl;
    cout << "3 - Sugeneruoti pažymius, vardus ir pavardes" << endl;
    cout << "4 - Nuskaityti duomenis iš failo" << endl;
    cout << "5 - Baigti darbą" << endl;
    cin >> p;
    switch (p)
    {
    case 4:
        Nuskaitymas(studentai);
        cout << "Kaip norėtum surūšiuoti rezultatus?" << endl;
        cout << "1 - pagal vardą" << endl;
        cout << "2 - pagal pavardę" << endl;
        cout << "3 - pagal vidurkį" << endl;
        cout << "4 - pagal medianą" << endl;
        cin >> k;
        if(k==1) sort(studentai.begin(), studentai.end(), PagalVarda);
        if(k==2) sort(studentai.begin(), studentai.end(), PagalPavarde);
        if(k==3) sort(studentai.begin(), studentai.end(), PagalVidurki);
        if(k==4) sort(studentai.begin(), studentai.end(), PagalMediana);
        NuskIsvedimas(studentai);
        break;
    case 5:
        return 0;
        break;
    default:
    {
        Ivedimas(studentai, p);
        cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
        cout << "1 - vidurkį" << endl;
        cout << "2 - medianą" << endl;
        cin >> k;
        Isvedimas(studentai, p, k);
    }
    break;
    }
}