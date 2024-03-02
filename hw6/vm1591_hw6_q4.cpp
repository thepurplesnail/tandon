#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void printDivisors(int num);

int main() {
    int n;
    cout << "Please enter a positive integer (>= 2): ";
    cin >> n;
    printDivisors(n);
    return 0;
}

void printDivisors(int num) {
    string str1 = "";
    string str2 = ""; 
    for (int i = 1; i <= sqrt(num); i++) {
        if ((num % i) == 0){
            str1 += to_string(i) + " ";
            int factor = num/i;
            if (factor > sqrt(num)) str2 = to_string(factor) + " " + str2;
        } 
    } cout << str1 << str2 << endl;
}