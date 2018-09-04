#include <cstdio>
#include <queue>
using namespace std;
int postorders[40];
int inorders[40];
struct Node {
    Node * left;
    Node * right;
    int v;
    Node(int v) : v(v) {}
};
Node * solve(int postorders[40], int inorders[40], int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    // printf("%d\n", postorders[pr]);
    Node *node = new Node(postorders[pr]);
    // if (pr == pl) {
    //     node->left = NULL;
    //     node->right = NULL;
    //     return node;
    // }
    int proot = postorders[pr];
    int iroot;
    for (int i = il; i <= ir; i++) {
        if (proot == inorders[i]) {
            iroot = i;
            break;
        }
    }
    node->left = solve(postorders, inorders, pl, pl + iroot - il - 1, il, iroot - 1);
    node->right = solve(postorders, inorders, pl + iroot - il, pr - 1, iroot + 1, ir);
    return node;
}
void levelTraversal(Node * head) {
    queue<Node*> q;
    q.push(head);
    bool is_first = true;
    while (!q.empty()) {
        Node * t = q.front();
        if (is_first) {
            is_first = false;
            printf("%d", t->v);
        } else {
            printf(" %d", t->v);
        }
        q.pop();
        if (t->left) {
            q.push(t->left);
        }
        if (t->right) {
            q.push(t->right);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    // 后序遍历
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorders[i]);
    }
    // 中序遍历
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorders[i]);
    }
    Node * head = solve(postorders, inorders, 0, n -1, 0, n -1);
    levelTraversal(head);
    return 0;
}