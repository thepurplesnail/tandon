#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void getIndices(int arr[], int arrSize, int min);

const int NUM_INPUTS = 5;
int main() {
    int nums[NUM_INPUTS];
    int num, min;
    cout << "Please enter " << NUM_INPUTS << " integers separated by a space:" << endl;
    for (int i = 0; i < NUM_INPUTS; i++) {
        cin >> num;
        nums[i] = num;
    }
    min = minInArray(nums, NUM_INPUTS);
    getIndices(nums, NUM_INPUTS, min);
    return 0;
}

int minInArray(int arr[], int arrSize) {
    int min = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < min){
            min = arr[i];
        } 
    } return min;
}

void getIndices(int arr[], int arrSize, int min) {
    cout << "The minimum value is "<< min <<", and it is located in the following indices: "; 
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min)
            cout << i << " ";
    }
}
