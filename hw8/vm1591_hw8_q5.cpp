#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, middle, last;
    cout << "Enter your name as follows: FIRST_NAME MIDDLE_NAME/INITIAL LAST_NAME: ";
    cin >> first >> middle >> last;
    cout << last << ", " << first << " " << middle.substr(0, 1) << ".";
}