#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void analyzeDividors(int m, int& outCountDivs, int& outSumDivs);
void runAnalyzeDividors(int m);

int main() {
    runAnalyzeDividors(50000);
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            outCountDivs++;
            outSumDivs += i;
            int factor = num/i;
            if (i != factor && factor != num) {
                outCountDivs++;
                outSumDivs += num/i;
            }
        } 
    }
}

bool isPerfect(int num) {
    int outCountDivs = 0;
    int outSumDivs = 0;
    analyzeDividors(num, outCountDivs, outSumDivs);
    return outSumDivs == num;
}

void runAnalyzeDividors(int m) {
    string perfectStr = "";
    string amicableStr = "";
    for (int i = 2; i <= m; i++) {
        if (isPerfect(i)) {
            perfectStr += to_string(i) + " ";
        } 
        int outCountDivs1 = 0;
        int outSumDivs1 = 0;
        analyzeDividors(i, outCountDivs1, outSumDivs1);

        int outCountDivs2 = 0;
        int outSumDivs2 = 0;
        analyzeDividors(outSumDivs1, outCountDivs2, outSumDivs2);
        if (outSumDivs2 <= m && i < outSumDivs1 && outSumDivs2 == i) amicableStr += "(" + to_string(i) + ", " + to_string(outSumDivs1) + ")\n";
    } 
    cout << "Perfect numbers from 2 to " << m << ": " << perfectStr << endl;
    cout << "Amicable pairs from 2 to " << m << ":" << endl;
    cout << amicableStr << endl;
}

