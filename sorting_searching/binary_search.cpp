#include <iostream>
#include <vector>
using namespace std;

int findN(vector<int> v, int n);
int main(){
    vector<int> v = {1, 4, 5, 7, 9, 12};
    int index = findN(v, 9);
    int index2 = findN(v, 13);
    cout << index << endl;
    cout << index2 << endl;
    return 0;
}

int findN(vector<int> v, int n) {
    int l = 0;
    int r = v.size() - 1;
    int m;

    while (l <= r) {
        m = (l + r) / 2;
        if (v[m] == n) return n;
        if (n < v[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}