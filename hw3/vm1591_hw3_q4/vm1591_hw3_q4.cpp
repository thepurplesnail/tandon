#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
    double n;
    int method;
    cout << "Please enter a Real number:" << endl;
    cin >> n;
    cout << 
        "Choose your rounding method:\n"
        "1. Floor round \n"
        "2. Ceiling round \n"
        "3. Round to the nearest whole number" << endl;
    cin >> method;

    switch (method) {
        case FLOOR_ROUND:
            cout << (int) n;
            break;
        case CEILING_ROUND:
            cout << (int) (n + 1);
            break;
        case ROUND:
            int n10 = n * 10;
            if (n10 % 10 < 5) cout << (int) n;
            else cout << (int) n + 1;
            break;
    }
}
