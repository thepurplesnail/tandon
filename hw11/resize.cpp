#include <iostream>
using namespace std;

void resize(int* &arr, int& arrSize);

int main(){
    int size = 5;
    int newSize = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = i * 2;
    int oneMore = 10;
    resize(arr, newSize);
    arr[size] = oneMore;
    size = newSize;
    for (int i = 0 ; i < newSize; i++) cout << arr[i] << " ";
    return 0;
}

void resize(int* &arr, int& arrSize) {
    int* temp = new int[arrSize * 2];
    for (int i = 0; i < arrSize; i++) {
        temp[i] = arr[i];
    } 
    arrSize *= 2;
    delete[] arr;
    arr = temp;
}