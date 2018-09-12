#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    string id;
    string name;
    int grade;
    Node(string id, string name, int grade) : id(id), name(name), grade(grade) {}
};
bool cmp1(Node * node1, Node* node2) {
    if (node1->id == node2->id) {
        return node1->id < node2->id;
    } else {
        return node1->id < node2->id;
    }
}
bool cmp2(Node * node1, Node* node2) {
    if (node1->name == node2->name) {
        return node1->id < node2->id;
    } else {
        return node1->name < node2->name;
    }
}
bool cmp3(Node * node1, Node* node2) {
    if (node1->grade == node2->grade) {
        return node1->id < node2->id;
    } else {
        return node1->grade < node2->grade;
    }
}
Node * nodes[100000 + 10];
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        nodes[i] = new Node(id, name, grade);
    }
    if (t == 1) {
        sort(nodes, nodes + n, cmp1);
    } else if (t == 2) {
        sort(nodes, nodes + n, cmp2);
    } else if (t == 3) {
        sort(nodes, nodes + n, cmp3);
    }
    for (int i = 0; i < n; i++) {
        cout << nodes[i]->id <<" " << nodes[i]->name << " " << nodes[i]->grade << endl;
    }
    return 0;
}