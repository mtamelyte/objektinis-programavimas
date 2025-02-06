#include "mano_lib.h"

int main(){
    int n=1;
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
            studentai[i].sum += studentai[i].nd[ii];
        }
        studentai[i].vid=studentai[i].sum/n;
    }
    for(int i=0; i<n; i++)
    {
        cout << (studentai[i].vid*0.4)+(studentai[i].egz*0.6) << endl;
    }
}