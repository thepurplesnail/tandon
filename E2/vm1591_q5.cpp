#include <iostream>
using namespace std;

void print_up_down(unsigned int n);
void print_up(unsigned int n);
void print_down(unsigned int n);

int main(){
    print_up_down(5);
    return 0;
}

void print_up_down(unsigned int n) {
    if (n == 0) return;
    print_up(n);
    print_down(n - 1);
}

void print_up(unsigned int n) {
    if (n == 0) return;
    print_up(n - 1);
    cout << n << endl;
}

void print_down(unsigned int n) {
    if (n == 0) return;
    cout << n << endl;
    print_down(n - 1);
}