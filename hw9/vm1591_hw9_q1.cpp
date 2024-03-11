#include <iostream>
#include <string>
using namespace std;

void readString(string s);
void analyzeLetter(char letter, int& a, int&b, int& c, int& d, int& e, int& f, int& g, int& h, int& i, int& j, int& k, int& l, int& m, int& n, int& o, int& p, int& q, int& r, int& s, int& t, int& u, int& v, int& w, int& x,int& y, int& z);
void printLetters(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x,int y, int z);

int main() {
    string str;
    cout << "Please enter a line of text:" << endl;
    getline(cin, str);

    readString(str);
    return 0;
}

void readString(string s){
    int wordCount = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s_letter = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    for (char ch : s) {
        if (ch == ' ' || ch == '.' || ch == ',') {
            wordCount++;            
        } else {
            analyzeLetter(ch, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s_letter, t, u, v, w, x, y, z);
        }
    } if (s[s.length() - 1] != '.') wordCount++;
    cout << wordCount << "\twords" << endl;
    printLetters(a , b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s_letter, t, u, v, w, x, y, z);
}

void analyzeLetter(char letter, int& a, int&b, int& c, int& d, int& e, int& f, int& g, int& h, int& i, int& j, int& k, int& l, int& m, int& n, int& o, int& p, int& q, int& r, int& s, int& t, int& u, int& v, int& w, int& x,int& y, int& z) {
    if (letter == 'a' || letter == 'A') a++;
    else if (letter == 'b' || letter == 'B') b++;
    else if (letter == 'c' || letter == 'C') c++;
    else if (letter == 'd' || letter == 'D') d++;
    else if (letter == 'e' || letter == 'E') e++;
    else if (letter == 'f' || letter == 'F') f++;
    else if (letter == 'g' || letter == 'G') g++;
    else if (letter == 'h' || letter == 'H') h++;
    else if (letter == 'i' || letter == 'I') i++;
    else if (letter == 'j' || letter == 'J') j++;
    else if (letter == 'k' || letter == 'K') k++;
    else if (letter == 'l' || letter == 'L') l++;
    else if (letter == 'm' || letter == 'M') m++;
    else if (letter == 'n' || letter == 'N') n++;
    else if (letter == 'o' || letter == 'O') o++;
    else if (letter == 'p' || letter == 'P') p++;
    else if (letter == 'q' || letter == 'Q') q++;
    else if (letter == 'r' || letter == 'R') r++;
    else if (letter == 's' || letter == 'S') s++;
    else if (letter == 't' || letter == 'T') t++;
    else if (letter == 'u' || letter == 'U') u++;
    else if (letter == 'v' || letter == 'V') v++;
    else if (letter == 'w' || letter == 'W') w++;
    else if (letter == 'x' || letter == 'X') x++;
    else if (letter == 'y' || letter == 'Y') y++;
    else z++;
}

void printLetters(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x,int y, int z) {
    if (a > 0) cout << a << "\ta" << endl;
    if (b > 0) cout << b << "\tb" << endl;
    if (c > 0) cout << c << "\tc" << endl;
    if (d > 0) cout << d << "\td" << endl;
    if (e > 0) cout << e << "\te" << endl;
    if (f > 0) cout << f << "\tf" << endl;
    if (g > 0) cout << g << "\tg" << endl;
    if (h > 0) cout << h << "\th" << endl;
    if (i > 0) cout << i << "\ti" << endl;
    if (j > 0) cout << j << "\tj" << endl;
    if (k > 0) cout << k << "\tk" << endl;
    if (l > 0) cout << l << "\tl" << endl;
    if (m > 0) cout << m << "\tm" << endl;
    if (n > 0) cout << n << "\tn" << endl;
    if (o > 0) cout << o << "\to" << endl;
    if (p > 0) cout << p << "\tp" << endl;
    if (q > 0) cout << q << "\tq" << endl;
    if (r > 0) cout << r << "\tr" << endl;
    if (s > 0) cout << s << "\ts" << endl;
    if (t > 0) cout << t << "\tt" << endl;
    if (u > 0) cout << u << "\tu" << endl;
    if (v > 0) cout << v << "\tv" << endl;
    if (w > 0) cout << w << "\tw" << endl;
    if (x > 0) cout << x << "\tx" << endl;
    if (y > 0) cout << y << "\ty" << endl;
    if (z > 0) cout << z << "\tz" << endl;
}