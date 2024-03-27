#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main () {
    int arr1[] = {2, -1, 3, 10};
    int arr2[] = {-1, 0, 1, 1, 2, 3, 10};

    int ans = sumOfSquares(arr1, 4);
    cout << ans << endl;

    bool isArrSorted = isSorted(arr2, 7);
    cout << isArrSorted << endl;
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 0) return 0;
    int lastInd = arrSize - 1;
    return arr[lastInd] * arr[lastInd] + sumOfSquares(arr, arrSize - 1); 
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize < 2) return true;
    int i = arrSize - 2;
    int j = arrSize - 1;
    return arr[i] <= arr[j] && isSorted(arr, arrSize - 1); 
}