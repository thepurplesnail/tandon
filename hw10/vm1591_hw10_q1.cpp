#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    int outWordsArrSize = 0;
    string * strArr = createWordsArray("There is no crying in baseball", outWordsArrSize);
    cout << "Number of words in sentence: " << outWordsArrSize << endl;
    for (int i = 0; i < outWordsArrSize; i++) {
        cout << strArr[i] << endl;
    }
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string w = "";
    for (char c : sentence) {
        if (c == ' ') outWordsArrSize++;
    }

    string* arr = new string[++outWordsArrSize];
    int j = 0;
    for (int i = 0; i < sentence.length(); i++) {
        char c = sentence[i];
        if (c == ' ') {
            arr[j++] = w;
            w = "";
        } else {
            w += c;
        }
    } 
    arr[j++] = w;
    return arr;
}
