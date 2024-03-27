#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void resizeArr(int*& arr, int& arrSize);
void printLines1(int* arr, int n, int size);
void printLines2(vector<int> arr, int n, int size);

int main(){
    main1();
    main2();
    return 0;
}

void main1(){
    int arrLength = 1;
    int * arr = new int[arrLength];
    int n;
    int counter = 0;

    int target; 
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1" << endl;
    while (n != -1) {
        cin >> n;
        if (n != -1) {
            if (counter + 1 == arrLength) resizeArr(arr, arrLength);
            arr[counter++] = n;
        }
    }
    cout << "Please enter a number you want to search." << endl;
    cin >> n;
    printLines1(arr, n, arrLength);
}

void main2(){
    int arrLength = 0;
    vector<int> v;
    int n;

    int target; 
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1" << endl;
    while (n != -1) {
        cin >> n;
        if (n != -1) {
            v.push_back(n);
        }
    }
    cout << "Please enter a number you want to search." << endl;
    cin >> n;
    printLines2(v, n, arrLength);
}

void resizeArr(int*& arr, int& size) {
    int newSize = size * 2;
    int* temp = new int[newSize];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    } size = newSize;
    delete[] arr;
    arr = temp;
}

void printLines1(int* arr, int n, int size) {
    int counter = 0;
    int j = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) counter++;
    } 
    cout << n << " shows up in lines ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            cout << i + 1;
            if (++j < counter) cout << ", ";
            else cout << ".";
        }
    } 

}

void printLines2(vector<int> arr, int n, int size) {
    cout << n << " shows up in lines ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == n) {
            int line = i + 1;
            cout << line;
            if (i < arr.size() - 1) cout << ", ";
            else cout << ".";
        }
    } 
}