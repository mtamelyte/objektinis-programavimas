#include "mano_lib.h"

int main(){
    int n=3;
    double sum=0;
    Stud studentai[n];
    for(int i=0; i<n; i++)
    {
        cout << i;
        cin >> studentai[i].var;
        cin >> studentai[i].pav; 
        cin >> studentai[i].egz;
        for(int ii=0; ii<n; ii++)
        {
            cin >> studentai[i].nd[ii];
            sum += studentai[i].nd[ii];
        }
    }
    double vid=sum/n;
}