#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int TOO_SMALL = -1;
const int TOO_BIG = 1;
const int CORRECT = 0;
const int MAX_TRIES = 5;

int compare(int guess, int x, int& lowerBound, int& upperBound);

int main() {
    int x;
    int guess;
    int lowerBound = 1;
    int upperBound = 100;
    int guessesTaken = 0;
    int status;
    srand(time(0));
    x = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try guessing it." << endl;

    while (guessesTaken < MAX_TRIES && status != 0){
        cout << "Range: [" << lowerBound << ", " << upperBound << "], Number of guesses left: " << (MAX_TRIES - guessesTaken++) << endl; 
        cin >> guess;
        status = compare(guess, x, lowerBound, upperBound);
        switch (status) {
            case TOO_SMALL:
                cout << "Your guess: " << guess << endl;
                cout << "Wrong! My number is bigger" << endl;
                break;
            case TOO_BIG:
                cout << "Your guess: " << guess << endl;
                cout << "Wrong! My number is smaller" << endl;
                break;
        }
    } 
    if (status == 0) cout << "Congrats! You guessed my number in " << guessesTaken << " guesses.";
    if (guessesTaken == 5) cout << "Out of guesses! My number is " << x << endl;
    return 0;
}

int compare(int guess, int x, int& lowerBound, int& upperBound) {
    if (guess < x) {
        if (guess > lowerBound) lowerBound = guess;
        return -1;
    } else if (guess > x) {
        if (guess < upperBound) upperBound = guess;
        return 1;
    } else return 0;
}