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
            cout << "5 - Testuoti kodą" << endl;
            cout << "6 - Baigti darbą" << endl;
            cin >> meniuPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw runtime_error("Įvedėte ne skaičių!");
            }
            else if (meniuPasirinkimas < 1 || meniuPasirinkimas > 6)
                throw runtime_error("Įvedėte netinkamą skaičių!");
            else
                break;
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
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
                    throw runtime_error("Įvedėte ne skaičių!");
                }
                else if (isvedimoPasirinkimas < 1 || isvedimoPasirinkimas > 2)
                    throw runtime_error("Įvedėte netinkamą skaičių!");
                else
                    break;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
                continue;
            }
        }
        cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
        cout << "1 - vidurkį" << endl;
        cout << "2 - medianą" << endl;
        cin >> galutinioBaloPasirinkimas;
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
        cout << "Galutinio balo skaičiavimui norėtum naudoti: " << endl;
        cout << "1 - vidurkį" << endl;
        cout << "2 - medianą" << endl;
        cin >> galutinioBaloPasirinkimas;
        rusiavimas(studentai);
        isvedimas(studentai, galutinioBaloPasirinkimas, cout);
    }
    break;
    }
}