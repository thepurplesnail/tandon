#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int n);
int getPow(int n);
int reverse(int n, int pow10);

int main () {
    if (isPalindrome(202)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

bool isPalindrome(int n) {
    int original = n;
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return original == rev;
}