#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct Node {
    string addr;
    int key;
    bool operator < (Node &node1) {
        return key < node1.key;
    }
};
vector<Node> vec;
map<string, pair<string, int> > m;
int main() {
    int n;
    string start_addr;
    cin >> n >> start_addr;
    for (int i = 0; i < n; i++) {
        Node node;
        string addr, target;
        int key; 
        cin >> addr >> key >> target; 
        m[addr] = make_pair(target, key);
    }
    string cur_node = start_addr;
    while (cur_node != "-1") {
        Node node;
        node.addr = cur_node; 
        node.key = m[cur_node].second;
        vec.push_back(node);
        cur_node = m[cur_node].first;
    }
    if (vec.size() == 0) {
        cout << "0 -1"  << endl;
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