#include<iostream>
#include<vector>
using namespace std;

void sortV(vector<int>& v, int l, int r);
void mergeV(vector<int>& v, int l, int r, int m);

int main(){
    vector<int> v = {14, 5, 8, 10, 13, 1, 18, 3};
    sortV(v, 0, v.size() - 1);
    for (int i : v) cout << i << " ";
    return 0;
}

void sortV(vector<int>& v, int l, int r) {
    if (l == r) return;
    int m = (l + r)/2;
    sortV(v, l, m);
    sortV(v, m + 1, r);
    mergeV(v, l, r, m);
}

void mergeV(vector<int>& v, int l, int r, int m) {
    int i1 = l;
    int i2 = m + 1;
    vector<int> temp;
    while (i1 <= m && i2 <= r) {
        if (v[i1] < v[i2]) temp.push_back(v[i1++]);
        else temp.push_back(v[i2++]);
    }
    for (int i = i1; i <= m; i++) temp.push_back(v[i]);
    for (int i = i2; i <= r; i++) temp.push_back(v[i]);

    for (int i = 0; i < temp.size(); i++) v[l++] = temp[i];
}
