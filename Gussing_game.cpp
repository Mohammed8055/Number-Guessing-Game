#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int maxNum, maxAttempts;
        int choice;

        cout << "\n=== Number Guessing Game ===" << endl;
        cout << "Select Difficulty:" << endl;
        cout << "1. Easy   (1-50,  10 attempts)" << endl;
        cout << "2. Medium (1-100, 7 attempts)" << endl;
        cout << "3. Hard   (1-200, 5 attempts)" << endl;
        cout << "Enter choice (1/2/3): ";
        cin >> choice;

        if (choice == 1) { maxNum = 50;  maxAttempts = 10; }
        else if (choice == 2) { maxNum = 100; maxAttempts = 7; }
        else { maxNum = 200; maxAttempts = 5; }

        int secretNumber = rand() % maxNum + 1;
        int guess, attempts = 0;

        cout << "\nI picked a number between 1 and " << maxNum << "." << endl;
        cout << "You have " << maxAttempts << " attempts!" << endl;

        while (attempts < maxAttempts) {
            cout << "\nAttempt " << attempts+1 << "/" << maxAttempts << " - Enter guess: ";
            cin >> guess;
            attempts++;

            if (guess == secretNumber) {
                cout << "🎉 Correct! You won in " << attempts << " attempts!" << endl;
                break;
            } else if (guess < secretNumber) {
                cout << "Too low! Try higher." << endl;
            } else {
                cout << "Too high! Try lower." << endl;
            }

            if (attempts == maxAttempts && guess != secretNumber) {
                cout << "Game Over! The number was " << secretNumber << endl;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}