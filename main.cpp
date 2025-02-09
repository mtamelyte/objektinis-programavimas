#include "mano_lib.h"

void Ivedimas(vector <Stud> & s, int n, int &p)
{
    bool nstud = true, npaz;
    int paz, pas;
    while (nstud)
    {
        Stud laik;
        npaz = true;
        cout << "Iveskite studento varda: ";
        cin >> laik.var;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> laik.egz;
        while (npaz)
        {
            cout << "Iveskite studento namu darbu pazymi: ";
            cin >> paz;
            laik.nd.push_back(paz);
            cout << "Ar norite ivesti dar viena pazymi?" << endl;
            cout << "1 - taip" << endl;
            cout << "2 - ne" << endl;
            cin >> pas;
            if (pas == 2)
                npaz = false;
        }
        s.push_back(laik);
        cout << "Ar norite ivesti dar viena studenta?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pas;
        if(pas ==2 ) nstud=false;
    }
    cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
    cout << "1 - vidurkį" << endl;
    cout << "2 - medianą" << endl;
    cin >> p;
}

double Vidurkis(vector <int> nd)
{
    double sum = 0;
    double vid;
    for (int i; i < 5; i++)
    {
        sum += nd[i];
    }
    vid = sum / 5;
    return vid;
}

double Mediana(vector <int> nd)
{
    sort(nd.begin(), nd.end());
    return nd[2];
}

void Isvedimas(vector <Stud> s, int n, int p)
{
    cout << setw(12) << left << "Pavardė";
    cout << setw(12) << "Vardas";
    if (p == 1)
        cout << setw(16) << "Galutinis (Vid.)" << endl;
    else if (p == 2)
        cout << setw(16) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------" << endl;
    for (Stud i : s)
    {
        cout << setw(12) << i.pav;
        cout << setw(12) << i.var;
        if (p == 1)
            cout << setw(16) << fixed << setprecision(2) << (Vidurkis(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        else if (p == 2)
            cout << setw(16) << fixed << setprecision(2) << (Mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
    }
}

int main()
{
    int n = 1, p;
    vector<Stud> studentai;
    Ivedimas(studentai, n, p);
    Isvedimas(studentai, n, p);
}