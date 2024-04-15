#include <iostream>
using namespace std;

int main(){
    // int arr[3] = {1, 2, 3};
    // cout << ++*arr << endl;
    // cout << arr[0] << endl;
    int x = 5;
    int* px = &x;
    ++px;
    int* b = px--;
    cout << b - px << endl;
    cout << px << endl;
    // cout << ++px << endl;
    cout << *px << endl;
    return 0;
}