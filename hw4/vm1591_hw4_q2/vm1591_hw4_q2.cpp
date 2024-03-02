#include <iostream>
using namespace std;

const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;

int main() {
	int n, q, userIn;
	string res;
	cout << "Enter decimal number: " << endl;
	cin >> userIn;
	n = userIn;

	while (n > 0) {
		if (n / M > 0) {
			q = n / M;
			for (int i = 0; i < q; i++) {
				res += "M";
			}
			n %= M;
		} else if (n / D > 0){
			q = n / D;
			for (int i = 0; i < q; i++) {
				res += "D";
			}
			n %= D;
		} else if (n / C > 0) {
			q = n / C;
			for (int i = 0; i < q; i++) {
				res += "C";
			}
			n %= C;
		} else if (n / L > 0) {
			q = n / L;
			for (int i = 0; i < q; i++) {
				res += "L";
			}
			n %= L ;
		} else if (n / X > 0) {
			q = n / X;
			for (int i = 0; i < q; i++) {
				res += "X";
			}
			n %= X;
		} else if (n / V > 0) {
			q = n / V;
			for (int i = 0; i < q; i++) {
				res += "V";
			}
			n %= V;
		} else {
			q = n / I;
			for (int i = 0; i < q; i++) {
				res += "I";
			}
			n %= I;
		} 
	}
	cout << userIn << " is " << res << endl;
	return 0;
}