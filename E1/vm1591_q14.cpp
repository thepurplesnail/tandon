#include <iostream>
using namespace std;

const int EXCELLENT_CUTOFF = 90;
const int VERY_GOOD_CUTOFF = 80;
const int AVERAGE_CUTOFF = 70;

int main() {
    int n;
    int excellent = 0;
    int veryGood = 0;
    int average = 0;
    int belowAverage = 0;
    int min = 101;
    int max = 0;
    double sum = 0;
    int headCount = 0;
    cout << "Please enter a sequence of numbers in between 1 and 100, each one in a separate line. End your sequence by typing -1:" << endl;
    while (n != -1) {
        cin >> n;
        if (n > -1){
            if (n < min) min = n;
            if (n > max) max = n;
            headCount++;
            sum += n;

            if (n >= EXCELLENT_CUTOFF) excellent++;
            else if (n >= VERY_GOOD_CUTOFF) veryGood++;
            else if (n >= AVERAGE_CUTOFF) average++;
            else belowAverage++;
        }
    } cout << "Number of students in the Excellent Category: " << excellent << endl;
    cout << "Number of students in the Very Good Category: " << veryGood << endl;
    cout << "Number of students in the Average Category: " << average << endl;
    cout << "Number of students in the Below Average Category: " << belowAverage << endl;
    cout << "Total number of people in the given sequence of scores: " << headCount << endl;
    cout << "Maximum score among the given sequence of scores: " << max << endl;
    cout << "Minimum score among the given sequence of scores: " << min << endl;
    cout << "Overall Average score of the given sequence of scores: " << sum/headCount << endl;
    return 0;
}