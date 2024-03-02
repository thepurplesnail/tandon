#include <iostream>
using namespace std;

int main() {
	int n, userIn;
	string res;
	cout << "Enter decimal number:" << endl;
	cin >> userIn;
	n = userIn;
	if (userIn == 0) cout << "The binary representation of " << userIn << " is 0" << endl;

	while (n > 0) {
		if (n % 2 == 0) res = "0" + res;
		else res = "1" + res;
		n /= 2;
	}
	cout << "The binary representation of " << userIn << " is " << res << endl;
	return 0;
}