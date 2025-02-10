#include "mano_lib.h"

void NaujasPaz(Stud1 & s, int laikp)
{
    int *kopija = new int[s.n];
    for (int i = 0; i < s.n-1; i++)
        {
            kopija[i] = s.nd[i];
        }
    kopija[s.n-1] = laikp;
    delete[] s.nd;
    s.nd = kopija;
}

void Ivedimas(vector <Stud1> &s, int &p)
{
    bool nstud = true, npaz;
    int paz, pas, laikp;
    while (nstud)
    {
        Stud1 laik;
        npaz = true;
        cout << "Iveskite studento varda: ";
        cin >> laik.var;
        cout << "Iveskite studento pavarde: ";
        cin >> laik.pav;
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> laik.egz;
        s.push_back(laik);
        while (npaz)
        {
            cout << "Iveskite studento namu darbu pazymi: ";
            cin >> laikp;
            s[s.size()-1].n++;
            NaujasPaz(s[s.size()-1], laikp);
            cout << "Ar norite ivesti dar viena pazymi?" << endl;
            cout << "1 - taip" << endl;
            cout << "2 - ne" << endl;
            cin >> pas;
            if (pas == 2)
                npaz = false;
        }
        cout << "Ar norite ivesti dar viena studenta?" << endl;
        cout << "1 - taip" << endl;
        cout << "2 - ne" << endl;
        cin >> pas;
        if (pas == 2)
            nstud = false;
    }
    cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
    cout << "1 - vidurkį" << endl;
    cout << "2 - medianą" << endl;
    cin >> p;
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
/*
void Isvedimas(vector <Stud1> s, int n, int p)
{
    cout << setw(12) << left << "Pavardė";
    cout << setw(12) << "Vardas";
    if (p == 1)
        cout << setw(16) << "Galutinis (Vid.)" << endl;
    else if (p == 2)
        cout << setw(16) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------" << endl;
    for (Stud1 i : s)
    {
        cout << setw(12) << i.pav;
        cout << setw(12) << i.var;
        if (p == 1)
            cout << setw(16) << fixed << setprecision(2) << (Vidurkis(i.nd) * 0.4) + (i.egz * 0.6) << endl;
        else if (p == 2)
            cout << setw(16) << fixed << setprecision(2) << (Mediana(i.nd) * 0.4) + (i.egz * 0.6) << endl;
    }
}
*/
int main()
{
    int p;
    vector<Stud1> studentai;
    Ivedimas(studentai, p);
    for (Stud1 i : studentai)
    {
        cout << i.var << " " << i.pav << endl;
        for (int ii = 0; ii < i.n; ii++)
        {
            cout << i.nd[ii] << endl;
        }
    }
    // Isvedimas(studentai, n, p);
}