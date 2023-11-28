#include <iostream>
#include "esercizio1.h"

using namespace std;

int main() {

    char res;
    messaggio mess{};
    queue q{};

    init(q);

    do {
        cout << "\nOperazioni possibili:\n"
             << "Enqueue (e)\n"
             << "Dequeue (d)\n"
             << "First (f)\n"
             << "Print (p)\n"
             << "Quit (q)\n";

        cin >> res;

        switch (res) {

            case 'e':
                cout << "Valore: ";
                cin >> mess.testo;
                cout << "Priorita' (>=0 e <=10): ";
                do {
                    cin >> mess.priority;
                } while (mess.priority < 0 || mess.priority > MAX_PRIORITY);
                if (!enqueue(q, mess)) {
                    cout << "Coda piena\n";
                }

                break;

            case 'd':
                if (!dequeue(q)) {
                    cout << "Coda vuota\n";
                }

                break;

            case 'f':
                if (!first(q, mess)) {
                    cout << "Coda vuota!\n";
                } else {
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