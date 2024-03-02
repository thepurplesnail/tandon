#include <iostream>
using namespace std;

const int DOLLAR_CENTS = 100;
const int QUARTER_CENTS = 25;
const int DIME_CENTS = 10;
const int NICKEL_CENTS = 5;
const int PENNY_CENTS = 1;

int main()
{
    int dollars, cents, quarters, dimes, nickels, pennies;
    cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    cin >> dollars >> cents;
    int total_cents = dollars * DOLLAR_CENTS + cents;

    quarters = total_cents / QUARTER_CENTS;
    total_cents %= QUARTER_CENTS;

    dimes = total_cents / DIME_CENTS;
    total_cents %= DIME_CENTS;

    nickels = total_cents / NICKEL_CENTS;
    total_cents %= NICKEL_CENTS;

    pennies = total_cents / PENNY_CENTS;
    
    cout << dollars << " dollars and " << cents << " are:\n" <<
        quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies\n";
}