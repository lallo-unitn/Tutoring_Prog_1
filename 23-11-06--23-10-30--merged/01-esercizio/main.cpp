#include <iostream>
#include <cstring>
#include "esercizio1.h"

using namespace std;

int main()
{
    pearson *pos;
    char surname[MAX_COGNOME];
    char name[MAX_COGNOME];
    pearson p;
    group g;
    char s[2];

    initGroup(g);
    do
    {
        cout << endl;
        cout << " i: add person\n";
        cout << " n: print list sorted by name\n";
        cout << " c: print list sorted by surname\n";
        cout << " o: search by name\n";
        cout << " g: search by surname\n";
        cout << " e: exit\n";
        cout << "\nInserisci Scelta: ";
        cin >> s;

        switch (s[0])
        {
        case 'i':
            setPearson(p);
            if (!addPersonToGroup
            (p, g))
                cout << "Group is full\n";
            break;
        case 'n':
            printGroupByName(g);
            break;
        case 'c':
            printGroupBySurname(g);
            break;
        case 'o':
            setName(name);
            pos = searchByName(name, g);
            if (pos == NULL)
                cout << "Not found\n";
            else
            {
                cout << "Found: " << endl;
                printPerson(*pos);
            }
            break;
        case 'g':
            setSurname(surname);
            pos = searchBySurname(surname, g);
            if (pos == NULL)
                cout << "Not found\n";
            else
            {
                cout << "Found: " << endl;
                printPerson(*pos);
            }
            break;
        case 'e':
            break;
        default:
            cout << "error\n";
        }
    } while ((s[0] == 'i' || s[0] == 'n' || s[0] == 'c' || s[0] == 'o' || s[0] == 'g'));
    return EXIT_SUCCESS;
}