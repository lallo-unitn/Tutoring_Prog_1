using namespace std;
#include <iostream>
#include <cstring>
#include "esercizio1.h"

int main()
{

    char res;
    messaggio mess;
    queue q;

    init(q);

    do
    {
        cout << "\nOperazioni possibili:\n"
             << "Enqueue (e)\n"
             << "Dequeue (d)\n"
             << "First (f)\n"
             << "Print (p)\n"
             << "Quit (q)\n";

        cin >> res;

        switch (res)
        {

        case 'e':
            cout << "Valore: ";
            cin >> mess.testo;
            cout << "Priorita': ";
            cin >> mess.priorita;
            if (!enqueue(q, mess))
            {
                cout << "Coda piena\n";
            }

            break;

        case 'd':
            if (!dequeue(q))
            {
                cout << "Coda vuota\n";
            }

            break;

        case 'f':
            if (!first(q, mess))
            {
                cout << "Coda vuota!\n";
            }
            else
            {
                cout << "First = " << mess.testo << endl;
            }

            break;

        case 'p':
            print(q);

            break;

        case 'q':
            break;

        default:
            cout << "Valore errato!\n";
        }
    } while (res != 'q');

    return 0;
}