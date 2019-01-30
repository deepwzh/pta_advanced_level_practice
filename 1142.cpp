#include <cstdio>
#include <set>
#include <iostream>
using namespace std;
int G[210][210];
int main() {
    int Nv, Ne;
    scanf("%d%d", &Nv, &Ne);
    for (int i = 0; i < Ne; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int n;
        set<int> s;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int d;
            scanf("%d", &d);
            s.insert(d);
        }
        bool flag = true;
        for (const int &t1: s) {
            for (const int &t2: s) {
                if (t1 != t2 && G[t1][t2] == 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "Not a Clique" << endl; 
            continue;
        }
        bool flag1 = false;
        for (int q = 1; q <= Nv; q++) {
            set<int> tmp = s;
            for (int p = 1; p <= Nv; p++) {
                if (G[p][q]) {
                    tmp.erase(p);
                }
            }
            if (tmp.empty()) {
                flag1 = true;
                break;
            }
        }
        if (!flag1) {
            cout << "Yes" << endl;
        } else {
            cout << "Not Maximal" << endl;
        }

    }
    return 0;
}
