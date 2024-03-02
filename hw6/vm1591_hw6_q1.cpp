#include <iostream>
using namespace std;

int fib(int n);
int main() {
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}