#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    double determinant, x1, x2;

    cout << "Please enter value of a : ";
    cin >> a;
    cout << "Please enter value of b : ";
    cin >> b;
    cout << "Please enter value of c : ";
    cin >> c;

    determinant = b * b - 4 * a * c;
    
    if (determinant < 0) {
        cout << "This equation has no real solution" << endl;
    } else {
        x1 = (-b + sqrt(determinant)) / 2 / a;
        x2 = (-b - sqrt(determinant)) / 2 / a;
        if (x1 == x2) cout << "This equation has a single real solution x = " << x1;
        else cout << "This equation has 2 real solutions x1 = " << x1 << " and x2 = " << x2;
    }
}