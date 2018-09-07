#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

char d2c(int d) {
    if (d <= 9) {
        return d + '0';
    } else {
        return d - 10 + 'A';
    }
}
string dto13(int d) {
    if (d == 0) {
        return "00";
    }
    string res = "";
    while (d) {
        res.insert(0, 1, d2c(d % 13));
        d /= 13;
    }
    if (res.size() == 1) {
        res.insert(0, "0");
    }
    return res;
}
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    cout << "#" << dto13(a) << dto13(b) << dto13(c) << endl;
    return 0;
}