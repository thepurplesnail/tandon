#include <iostream>
using namespace std;

int getCost(int arr[], int arrSize);
int getMin(int x, int y);

int main() {
    int arr[6] = {0, 1, 5, 16, 4, 20};
    int cost = getCost(arr, 6);
    cout << cost << endl;
    return 0;
}

int getCost(int arr[], int arrSize) {
    if (arrSize < 4) return arr[arrSize - 1];
    int now = arrSize - 1;
    return arr[now] + getMin(getCost(arr, arrSize - 2), getCost(arr, arrSize - 1));
}

int getMin(int x, int y) {
    if (x <= y) return x;
    return y;
}