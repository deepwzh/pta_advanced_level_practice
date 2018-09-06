#include <cstdio>
#include <vector>
#include <set>
using namespace std;
// int G[1000 + 10][1000 + 10];
int par[1000 + 10];
vector<pair<int,int> > vec;
set<int> sets;
int p, e, k;
void Init() {
    for (int i = 0; i < 1000 + 10; i++) {
        par[i] = i;
    }
}
int Find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = Find(par[x]);
    }
}
bool Same(int x,int y) {
    return Find(x) == Find(y);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        par[x] = y;
    }
}
int Count() {
    int cnt = 0;
    for (int i = 1; i <= p; i++) {
        if (par[i] == i) {
            cnt++;
        }
    }
    return cnt - 1;
}
int solve(int t) {
    Init();
    for (int i = 0; i < vec.size(); i++) {
        int a = vec[i].first;
        int b = vec[i].second;
        if (a == t || b == t) {
            continue;
        }
        if (!Same(a, b)) {
            Union(a, b);
        }
    }
    return Count() - 1;
}
int main(){ 
    scanf("%d%d%d", &p, &e, &k);
    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        vec.push_back(pair<int, int>(a, b));
    }
    for (int i = 0; i < k; i++) {
        int d;
        scanf("%d", &d);
        printf("%d\n", solve(d));
    }
    return 0;
}