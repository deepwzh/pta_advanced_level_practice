#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
bool is_prime(int num) {
    if (num <= 1) return false;
    int k = sqrt(num);
    for (int i = 2; i <= k; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
string d2x(int n, int radix) {
    string s = "";
    while (n) {
        string tmp;
        stringstream ss;
        ss << n%radix;
        ss >> tmp;
        s.insert(0, tmp);
        n/=radix;
    }
    return s;
}
int pow(int a, int b) {
    int sum = 1;
    while(b--) {
        sum *= a;
    }
    return sum;
}
int x2d(string n, int radix) {
    int sum = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        sum += (n[i] - '0') * pow(radix, n.size() - 1 - i);
    }
    return sum;
}
int main() {
    int num;
    int radix;
    while (cin >> num && num >= 0) {
        cin >> radix;
        string a = d2x(num, radix);
        cout << a << endl;
        reverse(a.begin(), a.end());
        cout << a << endl;
        int t = x2d(a, radix);
        cout << t << endl;
        if (is_prime(t) && is_prime(num)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}