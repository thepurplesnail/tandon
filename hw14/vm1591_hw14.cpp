#include <iostream>
#include <vector>
using namespace std;

vector<int> findMinMax(vector<int> v, int l, int r);
vector<int> getMinMax(vector<int> v1, vector<int> v2);

int main() {
    vector<int> v = {4, 7, 1, 6, -1, 5, 12, 22, 15, 11};
    vector<int> res = findMinMax(v, 0, v.size() - 1);
    for (int i:res) cout << i << " ";
    return 0;
}

vector<int> findMinMax(vector<int> v, int l, int r) {
    if (l == r) {
        vector<int> res = {v[l], v[r]};
        return res;
    } 
    int m = (l + r)/2;
    return getMinMax(findMinMax(v, l, m), findMinMax(v, m + 1, r));
}

vector<int> getMinMax(vector<int> v1, vector<int> v2) {
    vector<int> res;
    if (v1[0] < v2[0]) res.push_back(v1[0]);
    else res.push_back(v2[0]);

    if (v1[1] > v2[1]) res.push_back(v1[1]);
    else res.push_back(v2[1]);
    return res;
}