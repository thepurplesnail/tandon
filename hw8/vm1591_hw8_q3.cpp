#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

void reverseArray(int arr[], int arrSize) {
    int temp;
    for (int i = 0, j = arrSize - 1; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int numEvens = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[numEvens++] = arr[i];
        }
    }
    arrSize = numEvens;
}

void splitParity(int arr[], int arrSize) {
    int l = 0;
    int r = arrSize - 1;
    int temp;
    while (l < r) {
        while (arr[l] % 2 != 0 && l < r) l++;
        while (arr[r] % 2 == 0 && l < r) r--;
        if (l < r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
}