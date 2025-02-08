#include "mano_lib.h"


void Ivedimas(Stud s[], int n){
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
        sort(s[i].nd, s[i].nd+5);
        for(int ii=0; ii<5; ii++)
        {
            cout << s[i].nd[ii] << endl;
        }
    }
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

double Mediana(){

}

void Isvedimas(Stud s[], int n){
    cout << setw(12) << left << "Pavardė";
    cout << setw(12) << "Vardas";
    cout << setw(16) << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------" << endl;
    for(int i=0; i<n; i++)
    {
        cout << setw(12) << s[i].pav;
        cout << setw(12) << s[i].var;
        cout << setw(16) << (Vidurkis(s[i].nd)*0.4)+(s[i].egz*0.6) << endl;
    }
}

int main(){
    int n=1;
    Stud studentai[n];
    Ivedimas(studentai, n);
    Isvedimas(studentai, n);
}