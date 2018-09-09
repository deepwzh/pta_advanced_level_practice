/**
 * 反思：层次遍历，之前错误错在没想清楚。输出的值不是每一层的值，而是每一个节点的值
 */
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <iostream>
#include <cassert>

using namespace std;
struct Node {
    set<Node*> childs;
};
void bfs(Node * head) {
    queue<pair<int, Node*> > q;
    q.push(pair<int, Node*>(0, head));
    printf("%d", 0);
    int last_deep = 0;
    int cnt = 0;
    while (!q.empty()) {
        Node * node = q.front().second;
        int cur_deep = q.front().first;
        q.pop();
        if (last_deep != cur_deep) {
          printf(" %d", cnt);
          cnt = 0;
        }
        last_deep = cur_deep;
        set<Node*> list = node->childs;
        for (Node* tn : list) {
            if (!tn->childs.size()) {
                cnt++;
            } else {
                q.push(pair<int, Node*>(cur_deep + 1, tn));
            }
        }

    }
    printf(" %d\n", cnt);
}
int main() {
    int N, M;
    // while (true) {
        map<string, Node*> m;
        Node * head = NULL;
        scanf("%d", &N);
        if (!N) return 0;
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            string p;
            int k;
            cin >> p >> k;
            Node * node = new Node();
            if (p == "01") {
                head = new Node();
                m[p] = head;
                node = head;
            } else {
                if (m.count(p)) {
                    node = m[p];    
                } else {
                    node = new Node();
                    m[p] = node;
                    node->childs.clear();
                }
            }
            for (int j = 0; j < k; j++) {
                Node * child_node = NULL;
                string s;
                cin >> s;
                if (m.count(s)) {
                    child_node = m[s];
                } else {
                    child_node = new Node();
                    m[s] = child_node;
                    child_node->childs.clear();

                }
                node->childs.insert(child_node);
            }
        }
        if (head) bfs(head);
        else {cout << "1" << endl;}
    // }
    return 0;
}