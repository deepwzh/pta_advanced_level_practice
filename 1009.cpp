#include <cstdio>
#include <map>
using namespace std;
int main() {
    int n1, n2;
    map<int, double> m1, m2; 
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int a;
        double d;
        scanf("%d%lf", &a, &d);
        m1[a] = d;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int a;
        double d;
        scanf("%d%lf", &a, &d);
        m2[a] = d;
    }
    map<int, double> m;
    for (map<int, double>::iterator it1 = m1.begin(); it1 != m1.end(); it1++) {
        for (map<int, double>::iterator it2 = m2.begin(); it2!= m2.end(); it2++) {
            int key = it1->first + it2->first;
            double value = it1->second * it2->second;
            if (!m.count(key)) {
                m[key] = value; 
            } else {
                m[key] += value;
            }
            if (m[key] == 0) {
                m.erase(key);
            }
        }
    }
    printf("%u", m.size());
    for (map<int, double>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
        printf(" %d %.1lf", it->first, it->second);
    }
    printf("\n");
    return 0;
}