#include <string>
#include <iostream>
using namespace std;

bool isPalindrome (string str);

int main() {
    string word; 
    cout << "Please enter a word: ";
    cin >> word;
    if (isPalindrome(word)) 
        cout << word << " is a palindrome";
    else 
        cout << word << " is not a palindrome";
    return 0;
}

bool isPalindrome(string str) {
    for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) return false;
    } return true;
}