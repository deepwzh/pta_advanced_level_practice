#include <cstdio>
#include <vector>
using namespace std;
struct Node {
    Node * lchild;
    Node * rchild;
    int v;
    Node(int v) : v(v) {}
    Node() {}
};
Node * errnode = new Node(-1);
Node * build(int dir, int * postorder, int * preorder, int pol, int por, int prl, int prr) {
    if (pol > por) {
        return NULL;
    }
    int po_root = postorder[por];
    int pr_root = preorder[prl];
    if (po_root != pr_root) return errnode;
    Node * lchild, * rchild;
    bool has_success_node = false;
    int len = prr - prl + 1;
    if (dir == 1) {
        for (int i = 0; i <= len; i++) {
            lchild = build(dir, postorder, preorder, pol, pol + i - 1, prl + 1, prl + i);
            if (lchild == errnode)
                continue; 
            rchild = build(dir, postorder, preorder, pol + i, por - 1, prl + i + 1, prr);
            if (rchild == errnode)
                continue;
            has_success_node = true;
            break;
        }
    } else {
        for (int i = len; i >= 0; i--) {
            lchild = build(dir, postorder, preorder, pol, pol + i - 1, prl + 1, prl + i);
            if (lchild == errnode)
                continue; 
            rchild = build(dir, postorder, preorder, pol + i, por - 1, prl + i + 1, prr);
            if (rchild == errnode)
                continue;
            has_success_node = true;
            break;
        }

    }
    if (!has_success_node) return errnode; 
    Node * node = new Node();
    node->v = po_root;
    node->lchild = lchild;
    node->rchild = rchild;
    return node;
}
void get_inorder(Node * node, vector<int> & res) {
    if (node == NULL) return ;
    get_inorder(node->lchild, res);
    res.push_back(node->v);
    get_inorder(node->rchild, res);
} 
bool Same(Node * node1, Node * node2) {
    if (!node1 && !node2) return true;
    if (!node1 || !node2) return false;
    if (node1->v != node2->v) return false;
    return Same(node1->lchild, node2->lchild) && Same(node1->rchild, node2->rchild);
}
int main() {
    int N;
    scanf("%d", &N);
    int postorder[N];
    int preorder[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }

    Node * head1 = build(1, postorder, preorder, 0, N - 1, 0, N - 1);
    Node * head2 = build(-1, postorder, preorder, 0, N - 1, 0, N - 1);
    printf("%s\n", Same(head1, head2)?"Yes": "No");
    vector<int> res;
    get_inorder(head1, res);
    bool is_first = true;
    for (int i = 0; i < res.size(); i++) {
        if (is_first) {
            is_first = false;
        } else {
            printf(" ");
        }
        printf("%d", res[i]);
    }
    return 0;
}