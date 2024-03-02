#include <iostream>
using namespace std;

int main()
{
    int n;
    char letter = 'a';
    cout << "Enter a positive integer: ";
    cin >> n;
    int maxChars = 2 * n - 1;
    // printing 1st half
    for (int i = 0; i < n; i++) {
        string line = "";
        int outspaces = n - i - 1;
        for (int j = 0; j < outspaces; j++) line += " ";
        int len = maxChars - 2 * outspaces;
        for (int j = 0; j < len; j++) {
            if (j == 0 || j == len - 1) line += letter;
            else line += " ";
        } 
        cout << line << endl;
        letter++;
    }
    letter -= 2;
    // printing 2nd half
    for (int i = 1; i <= n - 1; i++) {
        string line = "";
        int outspaces = i;
        for (int j = 0; j < outspaces; j++) line += " ";
        int len = maxChars - 2 * outspaces;
        for (int j = 0; j < len; j++) {
            if (j == 0 || j == len - 1) line += letter;
            else line += " ";
        }
        cout << line << endl;
        letter--;
    }
    return 0;
}
