#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Set the range for the random number
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 100;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between LOWER_BOUND and UPPER_BOUND
    int secret_number = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << LOWER_BOUND << " and " << UPPER_BOUND << "." << endl;

    int player_guess;
    int attempts = 0;
    bool guessed = false;

    while (!guessed) {
        cout << "Make a guess: ";
        cin >> player_guess;
        attempts++;

        if (player_guess < LOWER_BOUND || player_guess > UPPER_BOUND) {
            cout << "Please guess a number between " << LOWER_BOUND << " and " << UPPER_BOUND << "." << endl;
        } else if (player_guess < secret_number) {
            cout << "Too low! Try again." << endl;
        } else if (player_guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } else {
            guessed = true;
            cout << "Congratulations! You've guessed the number " << secret_number << " in " << attempts << " attempts." << endl;
        }
    }

    return 0;
}