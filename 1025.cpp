#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    string id;
    int score;
    int localrank;
    int place;
    int rank;
    Node(string id, int score, int place): id(id), score(score), place(place) {}
};
bool cmp1(Node * node1, Node * node2) {
    if (node1->score == node2->score) {
        return node1->id < node2->id;
    }
    return node1->score > node2->score;
}
Node * nodes[30000 + 100];
int main() {
    int N;
    int cnt = 0;
    scanf("%d", &N);
    int last_pos = 0;
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            string id;
            int d;
            cin >> id >> d;
            nodes[cnt++] = new Node(id, d, i + 1); 
        }
        sort(nodes + last_pos, nodes + cnt, cmp1);
        int cur_rank = 1;
        for (int j = last_pos; j < cnt; j++) {
            if (j && nodes[j-1]->score == nodes[j]->score) {
                nodes[j]->localrank = nodes[j-1]->localrank;
            } else {
                nodes[j]->localrank = j - last_pos + 1;
            }
        }
        last_pos = cnt;
    }
    sort(nodes, nodes + cnt, cmp1);
    // int cur_rank = 1;
    for (int j = 0; j < cnt; j++) {
        if (j && nodes[j-1]->score == nodes[j]->score) {
            nodes[j]->rank = nodes[j-1]->rank;
        } else {
            nodes[j]->rank = j + 1;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << nodes[i]->id << " " << nodes[i]->rank << " " << nodes[i]->place << " " << nodes[i]->localrank << endl;
    }
    return 0;
}