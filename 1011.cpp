#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    double a = 0, b = 0, c = 0;
    char aa, bb, cc;
    for (int i = 0; i < 3; i++) {
        double d;
        scanf("%lf", &d);
        if (d > a) {
            a = d;
            if (i == 0) {
                aa = 'W';
            } else if (i == 1) {
                aa = 'T';
            } else if (i == 2) {
                aa = 'L';
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        double d;
        scanf("%lf", &d);
        if (d > b) {
            b = d;
            if (i == 0) {
                bb = 'W';
            } else if (i == 1) {
                bb = 'T';
            } else if (i == 2) {
                bb = 'L';
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        double d;
        scanf("%lf", &d);
        if (d > c) {
            c = d;
            if (i == 0) {
                cc = 'W';
            } else if (i == 1) {
                cc = 'T';
            } else if (i == 2) {
                cc = 'L';
            }
        }
    }
    printf("%c %c %c %.2lf\n", aa, bb, cc, ((a * b * c)*0.65 - 1)*2);
    return 0;
}