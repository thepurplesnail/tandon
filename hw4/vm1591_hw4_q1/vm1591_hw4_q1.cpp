#include <iostream>
using namespace std;

int main() {
	int n;
	int counterA = 1;

	cout << "Please enter a positive integer : ";
	cin >> n;

	cout << "section a" << endl;
	while (counterA <= n) {
		cout << counterA++ * 2 << endl;
	}
	cout << "section b" << endl;
	for (int counterB = 1; counterB <= n; counterB++) {
		cout << counterB * 2 << endl;
	} return 0;
}