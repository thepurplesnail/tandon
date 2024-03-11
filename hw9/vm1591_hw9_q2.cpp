#include <iostream>
using namespace std;

void analyzeStr(string s, int& a, int&b, int& c, int& d, int& e, int& f, int& g, int& h, int& i, int& j, int& k, int& l, int& m, int& n, int& o, int& p, int& q, int& r, int& sChar, int& t, int& u, int& v, int& w, int& x,int& y, int& z);
bool compareString(int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1, int i1, int j1, int k1, int l1, int m1, int n1, int o1, int p1, int q1, int r1, int sChar1, int t1, int u1, int v1, int w1, int x1, int y1, int z1, int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2, int i2, int j2, int k2, int l2, int m2, int n2, int o2, int p2, int q2, int r2, int sChar2, int t2, int u2, int v2, int w2, int x2, int y2, int z2);
bool isAnagram(string s1, string s2);

int main() {
    cout << isAnagram("Eleven plus two", "Twelve plus one");
    return 0;
}



bool isAnagram(string s1, string s2) {
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    int d1 = 0;
    int e1 = 0;
    int f1 = 0;
    int g1 = 0;
    int h1 = 0;
    int i1 = 0;
    int j1 = 0;
    int k1 = 0;
    int l1 = 0;
    int m1 = 0;
    int n1 = 0;
    int o1 = 0;
    int p1 = 0;
    int q1 = 0;
    int r1 = 0;
    int sChar1 = 0;
    int t1 = 0;
    int u1 = 0;
    int v1 = 0;
    int w1 = 0;
    int x1 = 0;
    int y1 = 0;
    int z1 = 0;

    int a2 = 0;
    int b2 = 0;
    int c2 = 0;
    int d2 = 0;
    int e2 = 0;
    int f2 = 0;
    int g2 = 0;
    int h2 = 0;
    int i2 = 0;
    int j2 = 0;
    int k2 = 0;
    int l2 = 0;
    int m2 = 0;
    int n2 = 0;
    int o2 = 0;
    int p2 = 0;
    int q2 = 0;
    int r2 = 0; 
    int sChar2 = 0;
    int t2 = 0;
    int u2 = 0;
    int v2 = 0;
    int w2 = 0;
    int x2 = 0;
    int y2 = 0;
    int z2 = 0;

    analyzeStr(s1, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, sChar1, t1, u1, v1, w1, x1, y1, z1);
    analyzeStr(s2, a2, b2, c2, d2, e2, f2, g2, h2, i2, j2, k2, l2, m2, n2, o2, p2, q2, r2, sChar2, t2, u2, v2, w2, x2, y2, z2);

    return compareString(
        a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, sChar1, t1, u1, v1, w1, x1, y1, z1,
        a2, b2, c2, d2, e2, f2, g2, h2, i2, j2, k2, l2, m2, n2, o2, p2, q2, r2, sChar2, t2, u2, v2, w2, x2, y2, z2
    );
}

void analyzeStr(string s, int& a, int&b, int& c, int& d, int& e, int& f, int& g, int& h, int& i, int& j, int& k, int& l, int& m, int& n, int& o, int& p, int& q, int& r, int& sChar, int& t, int& u, int& v, int& w, int& x,int& y, int& z) {
    for (char ch : s) {
        if (ch == 'a' || ch == 'A') a++;
        if (ch == 'b' || ch == 'B') b++;
        if (ch == 'c' || ch == 'C') c++;
        if (ch == 'd' || ch == 'D') d++;
        if (ch == 'e' || ch == 'E') e++;
        if (ch == 'f' || ch == 'F') f++;
        if (ch == 'g' || ch == 'G') g++;
        if (ch == 'h' || ch == 'H') h++;
        if (ch == 'i' || ch == 'I') i++;
        if (ch == 'j' || ch == 'J') j++;
        if (ch == 'k' || ch == 'K') k++;
        if (ch == 'l' || ch == 'L') l++;
        if (ch == 'm' || ch == 'M') m++;
        if (ch == 'n' || ch == 'N') n++;
        if (ch == 'o' || ch == 'O') o++;
        if (ch == 'p' || ch == 'P') p++;
        if (ch == 'q' || ch == 'Q') q++;
        if (ch == 'r' || ch == 'R') r++;
        if (ch == 's' || ch == 'S') sChar++;
        if (ch == 't' || ch == 'T') t++;
        if (ch == 'u' || ch == 'U') u++;
        if (ch == 'v' || ch == 'V') v++;
        if (ch == 'w' || ch == 'W') w++;
        if (ch == 'x' || ch == 'X') x++;
        if (ch == 'y' || ch == 'Y') y++;
        else if (ch == 'z' || ch == 'Z') z++;
    }
}

bool compareString(int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1, int i1, int j1, int k1, int l1, int m1, int n1, int o1, int p1, int q1, int r1, int sChar1, int t1, int u1, int v1, int w1, int x1, int y1, int z1, int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2, int i2, int j2, int k2, int l2, int m2, int n2, int o2, int p2, int q2, int r2, int sChar2, int t2, int u2, int v2, int w2, int x2, int y2, int z2) {
    return (
        a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2 && e1 == e2 &&
        f1 == f2 && g1 == g2 && h1 == h2 && i1 == i2 && j1 == j2 &&
        k1 == k2 && l1 == l2 && m1 == m2 && n1 == n2 && o1 == o2 &&
        p1 == p2 && q1 == q2 && r1 == r2 && sChar1 == sChar2 && t1 == t2 &&
        u1 == u2 && v1 == v2 && w1 == w2 && x1 == x2 && y1 == y2 &&
        z1 == z2
    );
}