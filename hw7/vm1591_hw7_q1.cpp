#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
string isLeapYear(int year);
void printYearCalender(int year, int startingDay);
void printMonth(int month, int year);
int getDaysInMonth(int month, int year);

const int MONTH_IN_A_YEAR = 12;

int main () {
    int year, startingDay;
    cout << "Please enter a year: ";
    cin >> year;
    cout << "Please enter a starting day (1 - 7): ";
    cin >> startingDay;
    printYearCalender(year, startingDay);
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    if (startingDay == 8) startingDay = 1;
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;  
    for (int i = 1; i < startingDay; i++){
        cout << "\t";
    } 
    int day = startingDay;
    for (int i = 1; i <= numOfDays; i++) {
        if (day <= 7) {
            cout << i << "\t";
            day++;
        } else {
            cout << "" << endl;
            cout << i << "\t";
            day = 2;
        }
    } 
    cout << "" << endl;
    cout << "" << endl;
    return --day;
}

string isLeapYear(int year) {
    if (year % 4 == 0){
        if (year % 400 == 0 || year % 100 != 0) return "true";
        return "false";
    } return "false";
}

void printYearCalender(int year, int startingDay) {
    for (int i = 1; i <= MONTH_IN_A_YEAR; i++) {
        printMonth(i, year);
        startingDay = printMonthCalendar(getDaysInMonth(i, year), startingDay) + 1;
    }
}

void printMonth(int month, int year) {
    switch(month) {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        default:
            cout << "December";
            break;
    } cout << " " << year << endl;
}

int getDaysInMonth(int month, int year) {
    string isLeapYr = isLeapYear(year);
    switch(month) {
        case 1:
            return 31;
        case 2:
            if (isLeapYr.compare("true") == 0) return 29;
            else return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        default:
            return 31;
    }
} 