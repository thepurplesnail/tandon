#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRow(int n);
void printRuler(int n);
void printLine(int n);

int main(){
    // printTriangle(10);
    // printOppositeTriangles(10);
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    if (n == 0) return;
    printTriangle(n - 1);
    printRow(n);
}

void printOppositeTriangles(int n) {
    if (n == 0) return;
    printRow(n);
    printOppositeTriangles(n - 1);
    printRow(n);
}

void printRow(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*" ;
    } cout << "" << endl;
}

void printRuler(int n) {
    if (n == 0) return;
    printRuler(n - 1);
    printLine(n);
    printRuler(n - 1);
}

void printLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "- " ;
    } cout << "" << endl;
}