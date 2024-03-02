#include <iostream>
using namespace std;

int main()
{
    int lines, numSpaces, numStars;
    cout << "Please input a positive integer: " << endl;
    cin >> lines;
   
    int rowLen = 2 * lines - 1;
    // printing the top half
    for (int row = 0; row < lines; row++) {     
        int numSpaces = row;
        int numStars = rowLen - numSpaces * 2;
        for (int j = 0; j < numSpaces; j++) cout << " ";
        for (int j = 0; j < numStars; j++) cout << "*";
        cout << "" << endl;
    }
    // printing the bottom half
    for (int row = lines - 1; row >= 0; row--) {
        numSpaces = row;
        numStars = rowLen - numSpaces * 2;
        for (int j = 0; j < numSpaces; j++) cout << " ";
        for (int j = 0; j < numStars; j++) cout << "*";
        cout << "" << endl;
    } return 0;
}