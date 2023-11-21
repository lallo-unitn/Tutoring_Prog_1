#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

// Constants
const int MAX_LENGTH = 8;

int encode(char* number) {
    int base = 1;
    int result = 0;

    for (int i = strlen(number) - 1; i >= 0; i--) {
        if (number[i] >= '0' && number[i] <= '9') {
            result += (number[i] - '0') * base;
        } else if (number[i] >= 'a' && number[i] <= 'z') {
            int value = 10 + (number[i] - 'a');
            result += value * base;
        }
        base = base * 36;
    }

    return result;
}

void decode(int coded, char* decoded) {
    int i = 0;

    while (coded != 0) {
        int modulo = coded % 36;
        coded = (coded - modulo) / 36;

        if (modulo < 10) {
            decoded[i] = '0' + modulo;
        } else {
            decoded[i] = 'a' + modulo - 10;
        }
        i++;
    }
    decoded[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char tmp = decoded[j];
        decoded[j] = decoded[i - 1 - j];
        decoded[i - 1 - j] = tmp;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: exercise1.out <input> <output>" << endl;
        exit(1);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail() || output.fail()) {
        cout << "Error opening streams!" << endl;
    }

    cout << "This program encodes a text word by word, adding the encoding key to each word." << endl
         << "Words are decoded as numbers in base 36, with ten digits 0...9 and twenty-six characters a...z." << endl
         << "Where "
         << "0->" << 0
         << ", "
         << "a->" << 10
         << ", "
         << "z->" << 35
         << ", "
         << "10->" << 36
         << ", "
         << "1z->" << 71
         << ", "
         << "20->" << 72
         << endl;

    char buffer[MAX_LENGTH];

    int key = 1;
    while (true) {
        cout << "Enter a number to use as an encryption key (up to 7 digits): ";
        cin >> buffer;
        if (strlen(buffer) <= 7)
            break;
    }
    key = atoi(buffer);
    cout << key << endl;

    while (input >> buffer) {
        cout << buffer;
        buffer[4] = '\0';

        int encoded;
        encoded = encode(buffer);
        cout << " (" << encoded << ") ";

        encoded += key;
        decode(encoded, buffer);
        cout << " -> encrypted " << buffer << " (" << encoded << ") ";
        output << buffer << " ";

        encoded = encode(buffer) - key;
        decode(encoded, buffer);
        cout << " -> decrypted " << buffer << " (" << encoded << ") " << endl;
    }

    input.close();
    output.close();

    return 0;
}
