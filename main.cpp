#include "mano_lib.h"

int main(){
    int n=1;
    Stud studentai[n];
    for(int i=0; i<n; i++)
    {
        cout << "Iveskite studento varda: ";
        cin >> studentai[i].var;
        cout << "Iveskite studento pavarde: ";
        cin >> studentai[i].pav;
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> studentai[i].egz;
        cout << "Iveskite studento tarpinius rezultatus: ";
        for(int ii=0; ii<5; ii++)
        {
            cin >> studentai[i].nd[ii];
            studentai[i].sum += studentai[i].nd[ii];
        }
        studentai[i].vid=studentai[i].sum/5;
    }
    cout << setw(12) << left << "Pavardė";
    cout << setw(12) << "Vardas";
    cout << setw(16) << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------" << endl;
    for(int i=0; i<n; i++)
    {
        cout << setw(12) << studentai[i].pav;
        cout << setw(12) << studentai[i].var;
        cout << setw(16) << (studentai[i].vid*0.4)+(studentai[i].egz*0.6) << endl;
    }
}