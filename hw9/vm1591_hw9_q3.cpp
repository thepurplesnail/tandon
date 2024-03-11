#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int outPosArrSize1 = 5;
    int *arr1 = new int[outPosArrSize1];
    arr1[0] = -1;
    arr1[1] = 3;
    arr1[2] = -3;
    arr1[3] = 2;
    arr1[4] = 2;
    arr1 = getPosNums1(arr1, outPosArrSize1, outPosArrSize1);
    for (int i = 0; i < outPosArrSize1; i++) cout << arr1[i] << " ";
    cout << endl;

    int outPosArrSize2 = 5;
    int *arr2 = new int[outPosArrSize2];
    arr2[0] = -1;
    arr2[1] = 3;
    arr2[2] = -3;
    arr2[3] = 2;
    arr2[4] = 2;
    arr2 = getPosNums2(arr2, outPosArrSize2, &outPosArrSize2);
    for (int i = 0; i < outPosArrSize1; i++) cout << arr1[i] << " ";
    cout << endl;
    
    int outPosArrSize3 = 5;
    int *arr3 = new int[outPosArrSize3];
    arr3[0] = -1;
    arr3[1] = 3;
    arr3[2] = -3;
    arr3[3] = 2;
    arr3[4] = 2;
    int *outPosArr3 = new int[outPosArrSize3];
    getPosNums3(arr3, outPosArrSize3, outPosArr3, outPosArrSize3);
    for (int i = 0; i < outPosArrSize3; i++) cout << outPosArr3[i] << " ";
    cout << endl;

    int outPosArrSize4 = 5;
    int *arr4 = new int[outPosArrSize4];
    arr4[0] = -1;
    arr4[1] = 3;
    arr4[2] = -3;
    arr4[3] = 2;
    arr4[4] = 2;
    int *outPosArr4 = new int[outPosArrSize4];
    
    getPosNums4(arr4, outPosArrSize4, &outPosArr4, &outPosArrSize4);
    for (int i = 0; i < outPosArrSize4; i++) cout << outPosArr4[i] << " ";
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int numPos = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) numPos++;
    }

    int *temp = new int[numPos];
    int currInd = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) temp[currInd++] = arr[i];
    } 
    delete[] arr;
    outPosArrSize = numPos;
    return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int numPos = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) numPos++;
    }

    int *temp = new int[numPos];
    int currInd = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) temp[currInd++] = arr[i];
    } 
    delete[] arr;
    *outPosArrSizePtr = numPos;
    return temp;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int numPos = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) numPos++;
    }

    int *temp = new int[numPos];
    int currInd = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) temp[currInd++] = arr[i];
    } 
    delete[] outPosArr;
    outPosArr = temp;
    outPosArrSize = numPos;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int numPos = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) numPos++;
    }

    int *temp = new int[numPos];
    int currInd = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) temp[currInd++] = arr[i];
    }
    *outPosArrPtr = temp; 
    *outPosArrSizePtr = numPos;
}