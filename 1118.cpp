#include <cstdio>
#include <set>
using namespace std;
int par[10000 + 10];
void Init() {
    for (int i = 1; i <= 10000; i++) {
        par[i] = i;
    }
}
int Find(int v) {
    if (v == par[v]) {
        return v;
    } else {
        return par[v] = Find(par[v]);
    }
}
void Union(int a, int b) {
    int ar = Find(a);
    int br = Find(b);
    if (ar != br) {
        par[ar] = br;
    }
}
bool Same(int a, int b) {
    return (Find(a) == Find(b)); 
}
int main() {
    int N;
    scanf("%d", &N);
    set<int> s;
    Init();
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        int last_d;
        if (K) {
            scanf("%d", &last_d);
            s.insert(last_d);
        }
        for (int j = 1; j < K; j++) {
            int d;
            scanf("%d", &d);
            s.insert(d);
            Union(last_d, d);
            last_d = d;
        }
    }
    int cnt = 0;
    for (int d: s) {
        if (par[d] == d) cnt++;
    }
    printf("%d %d\n", cnt ,s.size());
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (Same(a, b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}