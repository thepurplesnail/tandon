#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int resArrSize = 0;
    int arr[] = {0,3,1,3,4,5,7,2,4,10};
    int * res = findMissing(arr, 10, resArrSize);
    for (int i = 0; i < resArrSize; i++) {
        cout << res[i] << " ";
    }
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int tempLen = n + 1;
    int * temp = new int[tempLen];

    for (int i = 0; i < tempLen; i++) {
        temp[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int ind = arr[i];
        temp[ind] = ind;
    }

    for (int i = 0; i < tempLen; i++) {
        if (temp[i] < 0) resArrSize++;
    } 

    int * res = new int[resArrSize];
    int j = 0;
    for (int i = 0; i < tempLen; i++) {
        if (temp[i] < 0) res[j++] = i;
    }
    return res;
}