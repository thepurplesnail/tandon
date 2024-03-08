#include <iostream>
#include <string>
using namespace std;

string convertWord(string word, bool isNum);
bool isNumeric(char c);

int main() {
    string userIn;
    string res = "";
    string word;
    char c;
    bool isNum = true;
    cout << "Please enter a line of text: " << endl;
    getline(cin, userIn);
    for (int i = 0; i < userIn.length(); i++) {
        c = userIn[i];
        if (c == ' '){
            res += convertWord(word, isNum) + " ";
            word = "";
            isNum = true;
        } else {
            if (!isNumeric(c)) isNum = false;
            word += c;
        }
    }
    res += convertWord(word, isNum);
    cout << res;
    return 0;
}

string convertWord(string word, bool isNum) {
    if (isNum) {
        string s = "";
        for (int i = 0; i < word.length(); i++) s += "x";
        return s;
    }
    return word;
}

bool isNumeric(char c) {
    return (
        c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'
    );
}