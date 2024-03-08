#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateRandomArr(int arr[], int arrSize);
int getNum(int numArr[], int pw);
int getPowValue(int base, int pow);

const int ARR_SIZE = 10;
const int PW = 24913;

int main() {
    int arr[ARR_SIZE]; 
    int userIn;

    cout << "Please enter your pin according to the following mapping:" << endl;
    cout << "PIN:\t0 1 2 3 4 5 6 7 8 9" << endl;
    generateRandomArr(arr, ARR_SIZE);
    cout << "NUM:\t";
    for (int i = 0; i < ARR_SIZE; i++) cout << arr[i] << " ";
    cout << "" << endl;
    cin >> userIn;
    
    if (userIn == getNum(arr, PW)) cout << "Your PIN is correct";
    else cout << "Your PIN is not correct";
    return 0;
}


void generateRandomArr(int arr[], int arrSize) {
    srand(time(0));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % 3) + 1;
    }
}

int getNum(int numArr[], int pw) {
    int pow = 0;
    int num = 0;
    while (pw > 0) {
        num += numArr[pw % 10] * getPowValue(10, pow++);
        pw /= 10;
    }
    return num;
}

int getPowValue(int base, int pow) {
    int res = 1;
    for (int i = 0; i < pow; i++) {
        res *= base;
    } return res;
}