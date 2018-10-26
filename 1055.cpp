#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
    char name[9];
    int age;
    int value;
};
vector<Node> vec;
bool cmp(const Node & n1, const Node & n2) {
    if (n1.value == n2.value) {
        if (n1.age == n2.age) {
                for(int i = 0; i < 9; i++){
                    if(n1.name[i] < n2.name[i]) return true;
                    else if(n1.name[i] > n2.name[i]) return false;
                }
                return true;
        } else {
            return n1.age < n2.age;
        }
    }
    return n1.value > n2.value;
}
int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        Node node;
        scanf("%s%d%d" , node.name, &node.age, &node.value);
        vec.push_back(node);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < K; i++) {
        printf("Case #%d:\n", i + 1);
        int n, maxx, minn;
        scanf("%d%d%d", &n, &minn, &maxx);
        int res_cnt = 0;
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j].age >= minn && vec[j].age <= maxx) {
                printf("%s %d %d\n", vec[j].name, vec[j].age, vec[j].value);
                res_cnt++;
                if (res_cnt >= n) {
                  break;
                }
            }
        }
        if (res_cnt == 0) {
            puts("None");
        }
    }
    return 0;
}