#include <cstdio>
#include <map>
using namespace std;
int main() {
    int n1, n2;
    scanf("%d", &n1);
    map<int, double> m;
    for (int i = 0; i < n1; i++) {
        int a;
        double b;
        scanf("%d%lf", &a, &b);
        if (m.count(a)) {
            m[a] += b;
        } else {
            m[a] = b;
        }
        if (m[a] == 0) {
             m.erase(a);
        }
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int a;
        double b;
        scanf("%d%lf", &a, &b);
        if (m.count(a)) {
            m[a] += b;
        } else {
            m[a] = b;
        }
        if (m[a] == 0) {
             m.erase(a);
        }
    }
    printf("%u", m.size());
    for (map<int, double>::reverse_iterator  it = m.rbegin(); it != m.rend(); it++) {
        if (it->second > 0 || it->second <= -1e-6) {
            printf(" %d %.1lf", it->first, it->second);
        }
    }
    return 0;
}