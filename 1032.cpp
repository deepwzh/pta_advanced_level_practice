/**
 * 这道题目一开始思路是：用map表示链表关系。先循环其中一个链表，并保存其中的元素在set中。然后循环另一个链表判断每一个元素是否存在与set中。
 * 然后超时。删去其中一个循环可以得到不超时的结果。所以我把两个循环合成一个。具体代码如下
 */

#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;
map<string, string> m;
set<string> s;
int main() {
    int N;
    string node1, node2;
    cin >> node1 >> node2 >> N;
    for (int i = 0; i < N; i++) {
        string n1, c, n2;
        cin >> n1 >> c >> n2;
        m[n1] = n2;
    }
    m["-1"] = "-1";
    string cur_node1 = node1;
    string cur_node2 = node2;
    // s.insert(cur_node);
    while (m[cur_node1] != "-1" || m[cur_node2] != "-1") {
        // cout << cur_node1 << " " << cur_node2 << endl;
        if (s.count(cur_node1)) {
            cout << cur_node1 << endl;
            return 0;
        }
        if (s.count(cur_node2)) {
            cout << cur_node2 << endl;
            return 0;
        }
        s.insert(cur_node1);
        s.insert(cur_node2);
        if (cur_node1 == cur_node2) {
            cout << cur_node1 << endl;
            return 0;
        }
        cur_node1 = m[cur_node1];
        cur_node2 = m[cur_node2];
    }
    cout << "-1" << endl;
    return 0;
}