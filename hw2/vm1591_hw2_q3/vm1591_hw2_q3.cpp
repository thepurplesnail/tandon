#include <iostream>
using namespace std;

const int DAYS_HOURS = 24;
const int HOURS_MINUTES = 60;

int main()
{
    int days_john, hours_john, minutes_john, days_bill, hours_bill, minutes_bill;
    cout << "Please enter the number of days John has worked: ";
    cin >> days_john;
    cout << "Please enter the number of hours John has worked: ";
    cin >> hours_john;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutes_john;

    cout <<  "\nPlease enter the number of days Bill has worked: ";
    cin >> days_bill;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hours_bill;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutes_bill;

    int total_minutes = 
        (days_john + days_bill) * DAYS_HOURS * HOURS_MINUTES +
        (hours_john + hours_bill) * HOURS_MINUTES +
        minutes_john + minutes_bill;
    
    int days = total_minutes / (DAYS_HOURS * HOURS_MINUTES);
    total_minutes %= DAYS_HOURS * HOURS_MINUTES;
    int hours = total_minutes / HOURS_MINUTES;
    total_minutes %= HOURS_MINUTES;
    int minutes = total_minutes;

    cout << "\nThe total time both of them worked togethers is: " <<
        days << " days, " << hours << " hours, " << minutes << " minutes.";

}