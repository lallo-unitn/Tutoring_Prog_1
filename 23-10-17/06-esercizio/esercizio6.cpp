#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool is_prime(int n);

// Function to perform prime factorization
void fact_scomp(int input);

int main() {
    int input = 0;
    cout << "Inserisci un intero maggiore stretto di 1" << endl;  // Prompt the user to input an integer > 1
    cin >> input;  // Read the input from the user

    while (input <= 1) {
        system("clear");  // Clear the console screen (platform-specific)
        cout << "Input invalido \n";  // Display an error message for invalid input
        cout << "Inserisci un intero maggiore stretto di 1" << endl;  // Prompt for input again
        cin >> input;  // Read a new input
    }

    // Call the function to perform prime factorization
    fact_scomp(input);

    return EXIT_SUCCESS;  // Return success status
}

// Function to check if a number is prime
bool is_prime(int n) {
    bool res = true;

    // Loop through numbers from 2 to the square root of 'n' to check for divisibility
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res = false;  // If 'n' is divisible by 'i', it's not prime
        }
    }

    return res;  // Return true if 'n' is prime, false otherwise
}

// Function to perform prime factorization
void fact_scomp(int input) {
    // Loop through numbers from 2 to 'input' to check for prime factors
    for (int i = 2; input > 1; i++) {
        if (is_prime(i) && (input % i) == 0) {
            cout << i << "  ";  // Print the prime factor 'i'
            input /= i;  // Reduce 'input' by dividing it by 'i'
            i--;  // Decrement 'i' to continue checking for the same prime factor
        }
    }
    cout << endl;  // Print a newline to separate the factors
}
