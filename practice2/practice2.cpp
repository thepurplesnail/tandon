#include <iostream>
using namespace std;

/**
 * Given an array of numbers, write a function to move all 0s to the end of the array while
 * maintaining the relative order of the non-zero elements. Do this in-place. This should run in O(n)
*/
void reorder(int* arr, int arrSize) {
    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != 0) arr[j++] = arr[i];
    }
    for (int i = j; i < arrSize; i++) {
        arr[i] = 0;
    }
    
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}


int main() {
	int* arr = new int[5];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 0;
    arr[3] = 1;
    arr[4] = 0;
    printArr(arr, 5);
    reorder(arr, 5);
    printArr(arr, 5);
}
