#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int pos = 0;
    int cost = 0;
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        if (d > pos) {
            cost += (d - pos) * 6;
        } else {
            cost += (pos - d) * 4;
        }
        cost += 5;
        pos = d;
    }
    printf("%d\n", cost);
    return 0;
}