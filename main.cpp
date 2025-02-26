#include "mano_lib.h"

int main()
{
    srand(time(NULL));
    int galutinioBaloPasirinkimas = 0, meniuPasirinkimas;
    vector<Stud> studentai;
    cout << "Ką norėtum daryti?" << endl;
    cout << "1 - Suvesti duomenis ranka" << endl;
    cout << "2 - Sugeneruoti pažymius" << endl;
    cout << "3 - Sugeneruoti pažymius, vardus ir pavardes" << endl;
    cout << "4 - Nuskaityti duomenis iš failo" << endl;
    cout << "5 - Testuoti kodą" << endl;
    cout << "6 - Baigti darbą" << endl;
    cin >> meniuPasirinkimas;
    switch (meniuPasirinkimas)
    {
    case 4:
    {
        string failoPavadinimas;
        cout << "Įvesk failo, kurį nori nuskaityti, pavadinimą:" << endl;
        cin >> failoPavadinimas;
        nuskaitymasSuBuferiu(studentai, failoPavadinimas);
        rusiavimas(studentai);
        int isvedimoPasirinkimas;
        cout << "Kaip norite išvesti duomenis?" << endl;
        cout << "1 - į terminalą" << endl;
        cout << "2 - į failą" << endl;
        cin >> isvedimoPasirinkimas;
        if (isvedimoPasirinkimas == 1)
            isvedimas(studentai, isvedimoPasirinkimas);
        else
            isvedimasIFaila(studentai);
    }
    break;
    case 5:
    {
        cout << "Su kuriuo failu norėtumėte testuoti kodą?" << endl;
        cout << "1 - studentai10000.txt" << endl;
        cout << "2 - studentai100000.txt" << endl;
        cout << "3 - studentai1000000.txt" << endl;
        int failoPasirinkimas;
        cin >> failoPasirinkimas;
        switch (failoPasirinkimas)
        {
        case 1:
            testas("studentai10000.txt");
            break;
        case 2:
            testas("studentai100000.txt");
            break;
        case 3:
            testas("studentai1000000.txt");
            break;
        }
    }
    break;
    case 6:
    {
        return 0;
        break;
    }
    default:
    {
        ivedimas(studentai, meniuPasirinkimas);
        cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
        cout << "1 - vidurkį" << endl;
        cout << "2 - medianą" << endl;
        cin >> galutinioBaloPasirinkimas;
        rusiavimas(studentai);
        isvedimas(studentai, galutinioBaloPasirinkimas);
    }
    break;
    }
}