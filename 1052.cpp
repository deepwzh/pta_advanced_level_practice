#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
    string addr;
    int key;
    bool operator < (Node &node1) {
        return key < node1.key;
    }
};
vector<Node> vec;
int main() {
    int n;
    string addr;
    cin >> n >> addr;
    for (int i = 0; i < n; i++) {
        Node node;
        string next;
        cin >> node.addr >> node.key >> next; 
        vec.push_back(node);
    }
    if (vec.size() == 0) {
        cout << n << " " << -1 << endl;
        return 0;
    }
    sort(vec.begin(), vec.end());
    cout << n << " " << vec[0].addr << endl;
    Node node;
    node.addr = "-1";
    vec.push_back(node);
    for (int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i].addr << " " << vec[i].key << " "<< vec[i + 1].addr << endl;
    }
    // scanf("%d", &n, &addr);
    return 0;
}