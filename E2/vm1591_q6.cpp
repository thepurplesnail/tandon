#include <iostream>
using namespace std;
#include <vector>

void removeOdds(vector<int>& v);

int main(){
    vector<int> v =  {100, 75, 20, 15, 5, 2, 6};
    removeOdds(v);
    for (int n : v) cout << n << " ";
    return 0;
}

void removeOdds(vector<int>& v) {
    int j = 0;
    for (int n : v) {
        if (n % 2 == 0) v[j++] = n;
    }
    v.resize(j);
}