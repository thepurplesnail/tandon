#include <iostream>
using namespace std;

void resizeArray(int*& arr, int& size, int n) {
	int *temp = new int[size * 2];
	for (int i = 0; i < size; i++) temp[i] = arr[i];
	temp[size] = n;
    
	delete[] arr;
	arr = temp;
	size *= 2;
} 

int main() {
	int size = 4;
	int * arr = new int[size];
	for (int i = 0; i < size; i++) arr[i] = i * 10;
	int oneMore = 40;
	resizeArray(arr, size, oneMore);
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}