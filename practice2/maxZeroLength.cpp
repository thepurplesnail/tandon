#include <iostream>
using namespace std;

int getMax(int x, int y) {
    if (x > y) return x;
    return y;
}

int maxZeroLength(int* arr, int size, int countNow, int maxCount) {
    if (size == 0) return maxCount;
    if (arr[size - 1] == 0) {
        maxCount = getMax(++countNow, maxCount);
    } else countNow = 0;
    return maxZeroLength(arr, size - 1, countNow, maxCount);
}

int main() {
    int * arr = new int[6];
    for (int i = 0; i < 6; i++) arr[i] = 0;
    arr[0] = 1;
    arr[2] = 1;
    arr[4] = 5;

    int res = maxZeroLength(arr, 6, 0, 0);
    cout << res << endl;
    return 0;
}