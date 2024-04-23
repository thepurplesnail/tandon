#include <iostream>
#include <vector>
using namespace std;

void sortV(vector<int>& v);

int main(){
    vector<int> v = {3,1,3,1,4};
    sortV(v);
    for (int i : v) cout << i << " ";
    return 0;
}

void sortV(vector<int>& v) {
    int min, temp;
    for (int i = 0; i < v.size(); i++) {
        min = v[i];
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < min) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}