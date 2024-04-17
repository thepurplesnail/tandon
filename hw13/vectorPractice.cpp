#include <iostream>
#include <vector>
using namespace std;

// how to change vector in memory

void addOne(vector<int>& v) {
    v.push_back(1);
}

void removeInt(vector<int>& v, int target) {
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!(v[i] == target)) v[j++] = v[i];
    } 
}
int main(){
    vector<int> v = {1, 2, 3};
    addOne(v);
    for (int i: v) cout << i << " ";
    return 0;
}