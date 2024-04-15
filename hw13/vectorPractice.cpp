#include <iostream>
#include <vector>
using namespace std;

// how to change vector in memory

void addOne(vector<int>& v) {
    v.push_back(1);
}

int main(){
    vector<int> v = {1, 2, 3};
    addOne(v);
    for (int i: v) cout << i << " ";
    return 0;
}