#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please enter a positive odd integer: ";
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) cout << "*";
        } else {
            for (int j = 0; j < (n - i)/2; j++) cout << " ";
            for (int j = 0; j < i; j++) cout << "*";
        } 
        cout << "" << endl;
    }

    for (int i = 0; i < n; i++) cout << "*";
    cout << "" << endl;
    for (int i = 0; i < n; i++) cout << "*";
    cout << "" << endl;
    return 0;
}