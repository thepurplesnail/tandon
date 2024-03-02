#include <iostream>
using namespace std;

int main()
{
	int n;
	int numNow, numDigits = 0, numEven = 0;
	cout << "Please enter a positive integer: ";
	cin >> n;
	// go through all of the numbers from 1 to n
	for (int i = 1; i <= n; i++) {
		numNow = i;
		numDigits = 0;
		numEven = 0;

		// get each digit
		while (numNow > 0) {
			int digit = numNow % 10;
			// check if digit is even
			if (digit % 2 == 0) numEven++;
			numDigits++;
			numNow /= 10;
		}
		// if i has more even than odd digits -> print
		if (numEven > numDigits / 2) cout << i << endl;
	} return 0;
}