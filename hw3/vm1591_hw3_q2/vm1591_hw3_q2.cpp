#include <iostream>
using namespace std;

const string NOT_IN_COLLEGE = "not in college yet";
const string FRESHMAN = "freshman";
const string SOPHOMORE = "sophomore";
const string JUNIOR = "junior";
const string SENIOR = "senior";
const string GRADUATED = "graduated";

int main()
{
    string name, status;
    int difference, graduation_yr, current_yr;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduation_yr;
    cout << "Please enter current year: ";
    cin >> current_yr;
    difference = graduation_yr - current_yr;
    
    if (difference < 0) status = GRADUATED;
    else if (difference == 1) status = SENIOR;
    else if (difference == 2) status = JUNIOR;
    else if (difference == 3) status = SOPHOMORE;
    else if (difference == 4) status = FRESHMAN;
    else status = NOT_IN_COLLEGE;

    cout << name << ", you are " << status << endl;
}