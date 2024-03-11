#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main(){
    int arr[] = {5, 2, 11, 4, 9, 7, 6, 9, 8, 11, 10, 14};
    oddsKeepEvensFlip(arr, 12);
    for (int i : arr) cout << i << " ";
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int *copyArr = new int[arrSize];
    int currInd = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) copyArr[currInd++] = arr[i];
    }

    for (int i = arrSize - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) copyArr[currInd++] = arr[i];
    }

    for (int i = 0; i < arrSize; i++) arr[i] = copyArr[i];
}