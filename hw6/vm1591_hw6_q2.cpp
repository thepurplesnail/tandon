#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main(){
    int n, m;
    char symbol;
    cout << "Please enter desired number of lines: ";
    cin >> n;
    cout << "Please enter offset: ";
    cin >> m;
    cout << "Please enter symbol: ";
    cin >> symbol;
    printShiftedTriangle(n, m, symbol);
    
    int pineTreeN;
    char pineTreeSymbol;
    cout << "Please enter desired number of triangles: ";
    cin >> pineTreeN;
    cout << "Please enter symbol: ";
    cin >> pineTreeSymbol;
    printPineTree(pineTreeN, pineTreeSymbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int rowLen = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        int numChars = i * 2 + 1;
        int numSpaces = (rowLen - numChars)/2;
        for (int i = 0; i < (numSpaces + m); i++) cout << " ";
        for (int i = 0; i < numChars; i++) cout << symbol;
        for (int i = 0; i < numSpaces; i++) cout << " ";
        cout << "" << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 0; i < n; i++) {
        printShiftedTriangle(2 + i, n - 1 - i, symbol);
    }
}