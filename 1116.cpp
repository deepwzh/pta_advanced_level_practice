#include <cstdio>
#include <map>
#include <set>
#include <cmath>
using namespace std;
map<int, int> m;
bool is_prime(int d) {
    if (d == 1 || d == 0) return false;
    int k = sqrt(d);
    for (int i = 2; i <= k; i++) {
        if (d % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        m[d] = i;
    }
    int M;
    scanf("%d", &M);
    set<int> s;
    for (int i = 0; i < M; i++) {
        int d;
        scanf("%d", &d);
        if (!m.count(d)) {
            printf("%04d: Are you kidding?\n", d);
        } else {
            if (s.count(d)) {
                printf("%04d: Checked\n", d);
                continue;
            } else {
                s.insert(d);
            }
            if (m[d] == 0) {
                printf("%04d: Mystery Award\n", d);
            } else if (is_prime(d)) {
                printf("%04d: Minion\n", d);
            } else {
                printf("%04d: Chocolate\n", d);
            }
        }
    }
}