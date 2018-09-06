#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.size();
    int n1 = 0;
    for (int i = 3; i < len; i++) {
        int t = len + 2 - i;
        if (t % 2 != 0) {
            continue;
        } else if (t/2 <= i) {
           n1 = max(n1, t/2); 
        }
    }
    for (int i = 0; i < n1 - 1; i++) {
        printf("%c", s[i]);
        int n2 = len - n1*2;
        for (int j = 0; j < n2; j++) {
            printf(" ");
        }
        printf("%c\n", s[len - 1 - i]);
    }
    for (int i = n1 - 1; i <= len - n1; i++) {
        printf("%c", s[i]);
    }
    return 0;
}