#include <cstdio>
#include <algorithm>
using namespace std;
int D[100000 + 10];
int main() {
    int n;
    scanf("%d", &n);
    D[0] = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        scanf("%d", &d);
        D[i] = D[i-1] + d;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        int v = D[b - 1] - D[a - 1];
        printf("%d\n", min(v, D[n] - v));
    }
    return 0;
}