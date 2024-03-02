#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int lenA, lenB;
	int resA = 1;
	int resB = 1;
	int n; 
	cout << "section a" << endl;
	cout << "Please enter the length of the sequence: ";
	cin >> lenA;
	cout << "Please enter your sequence" << endl;
	for (int i = 0; i < lenA; i++) {
		cin >> n;
		resA *= n;
	}
	cout << "The geometric mean is: " << pow(resA,1.0/lenA) << endl;

	cout << "section b" << endl;
	cout << "Please enter the length of the sequence: ";
	cin >> lenB;
	cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
	while (n != -1) {
		cin >> n;
		resB *= n;
	} resB *= -1;
	cout << "The geometric mean is: " << pow(resB, 1.0/lenB) << endl;
	return 0;
}