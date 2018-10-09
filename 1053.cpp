#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
vector<int> node_weight;
bool cmp(const int& lhs, const int& rhs)
  {return node_weight[lhs]>node_weight[rhs];
}
map<int, vector<int> > m;
map<int, int> path;

void print_path(int v) {
    if (v == -1) {
        return ;
    }
    print_path(path[v]);
    printf("%d ", node_weight[v]);
}
void dfs(int n, int dis, int S) {
    if (!m.count(n)) {
        if (dis == S) {
            print_path(path[n]);
            printf("%d\n", node_weight[n]);
        }
        return;
    }
    sort(m[n].begin(), m[n].end(), cmp);
    for (const int & s: m[n]) {
        path[s] = n; 
        dfs(s, dis + node_weight[s], S);
    }
}
int main() {
    int N, M, S;
    scanf("%d%d%d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        node_weight.push_back(d);
    }
    for (int i = 0; i < M; i++) {
        int p;
        scanf("%d", &p);
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int node;
            scanf("%d", &node);
            m[p].push_back(node);
        }
    }
    path[0] = -1;
    dfs(0, node_weight[0], S);
    return 0;
}