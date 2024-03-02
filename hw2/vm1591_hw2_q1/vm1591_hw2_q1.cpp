#include <iostream>
using namespace std;

const int QUARTER_CENTS = 25;
const int DIME_CENTS = 10;
const int NICKEL_CENTS = 5;
const int PENNY_CENTS = 1;

int main()
{
    int quarters, dimes, nickels, pennies;
    cout << "Please enter number of coins:\n" <<
        "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;
    
    int total_cents = quarters * QUARTER_CENTS + dimes * DIME_CENTS + nickels * NICKEL_CENTS + pennies * PENNY_CENTS;
    int dollars = total_cents / 100;
    int cents = total_cents % 100;

    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;
}