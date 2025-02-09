#include "mano_lib.h"


void Ivedimas(Stud s[], int n, int & p){
    for(int i=0; i<n; i++ )
    {
        cout << "Iveskite studento varda: ";
        cin >> s[i].var;
        cout << "Iveskite studento pavarde: ";
        cin >> s[i].pav;
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> s[i].egz;
        cout << "Iveskite studento tarpinius rezultatus: ";
        for(int ii=0; ii<5; ii++)
        {
            cin >> s[i].nd[ii];
        }

    }
        cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
        cout << "1 - vidurkį" << endl;
        cout << "2 - medianą" << endl;
        cin >> p;
}

double Vidurkis(int nd[]){
    double sum=0;
    double vid;
        for(int i; i<5; i++)
        {
            sum += nd[i];
        }
        vid=sum/5;
    return vid;
}

double Mediana(int nd[]){
    sort(nd, nd+5);
    return nd[2];
}

void Isvedimas(Stud s[], int n, int p){
    cout << setw(12) << left << "Pavardė";
    cout << setw(12) << "Vardas";
    if(p==1) cout << setw(16) << "Galutinis (Vid.)" << endl;
    else if(p==2) cout << setw(16) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------" << endl;
    for(int i=0; i<n; i++)
    {
        cout << setw(12) << s[i].pav;
        cout << setw(12) << s[i].var;
        if(p==1)  cout << setw(16) << fixed << setprecision(2) << (Vidurkis(s[i].nd)*0.4)+(s[i].egz*0.6) << endl;
        else if(p==2) cout << setw(16) << fixed << setprecision(2) << (Mediana(s[i].nd)*0.4)+(s[i].egz*0.6) << endl;
    }
}

int main(){
    int n=1, p;
    Stud studentai[n];
    Ivedimas(studentai, n, p);
    Isvedimas(studentai, n, p);
}