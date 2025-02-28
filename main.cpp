#include "mano_lib.h"
#include "antrastes.h"

int main()
{
    srand(time(NULL));
    std::setlocale(LC_ALL, "en_US.UTF-8");
    int galutinioBaloPasirinkimas = 0, meniuPasirinkimas;
    vector<Stud> studentai;
    while (true)
    {
        try
        {
            cout << "Ką norėtum daryti?" << endl;
            cout << "1 - Suvesti duomenis ranka" << endl;
            cout << "2 - Sugeneruoti pažymius" << endl;
            cout << "3 - Sugeneruoti pažymius, vardus ir pavardes" << endl;
            cout << "4 - Nuskaityti duomenis iš failo" << endl;
            cout << "5 - Testuoti kodą ir išvesti 3 laikų vidurkį" << endl;
            cout << "6 - Baigti darbą" << endl;
            cin >> meniuPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw "Įvedėte ne skaičių!";
            }
            else if (meniuPasirinkimas < 1 || meniuPasirinkimas > 6)
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
    switch (meniuPasirinkimas)
    {
    case 4:
    {
        int isvedimoPasirinkimas;
        nuskaitymasSuBuferiu(studentai, failoPasirinkimas("Iš kurio failo norėtumėte nuskaityti duomenis?"));
        rusiavimas(studentai);
        while (true)
        {
            try
            {
                cout << "Kaip norite išvesti duomenis?" << endl;
                cout << "1 - į terminalą" << endl;
                cout << "2 - į failą" << endl;
                cin >> isvedimoPasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    throw "Įvedėte ne skaičių!";
                }
                else if (isvedimoPasirinkimas < 1 || isvedimoPasirinkimas > 2)
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
        while (true)
        {
            try
            {
                cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
                cout << "1 - vidurkį" << endl;
                cout << "2 - medianą" << endl;
                cin >> galutinioBaloPasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    throw "Įvedėte ne skaičių!";
                }
                else if (galutinioBaloPasirinkimas < 1 || galutinioBaloPasirinkimas > 2)
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
        if (isvedimoPasirinkimas == 1)
            isvedimas(studentai, galutinioBaloPasirinkimas, cout);
        else
        {
            ofstream fout("rez.txt");
            isvedimas(studentai, galutinioBaloPasirinkimas, fout);
        }
    }
    break;
    case 5:
    {
        testas(failoPasirinkimas("Su kuriuo failu norėtumėte testuoti kodą?"));
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
        while (true)
        {
            try
            {
                cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
                cout << "1 - vidurkį" << endl;
                cout << "2 - medianą" << endl;
                cin >> galutinioBaloPasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    throw "Įvedėte ne skaičių!";
                }
                else if (galutinioBaloPasirinkimas < 1 || galutinioBaloPasirinkimas > 2)
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
        rusiavimas(studentai);
        isvedimas(studentai, galutinioBaloPasirinkimas, cout);
    }
    break;
    }
}