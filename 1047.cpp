#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
char student_map[40000 + 20][5];
bool cmp(const int& lhs, const int& rhs){
    return strcmp(student_map[lhs], student_map[rhs]) < 0;
}
vector<int> courses[2500 + 10];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int C;
        scanf("%s %d", student_map[i], &C);
        for (int j = 0; j < C; j++) {
            int d;
            scanf("%d", &d);
            courses[d].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        cout <<  i  << " " << courses[i].size() << endl;
        sort(courses[i].begin(), courses[i].end(), cmp);
        for (int j = 0; j < courses[i].size(); j++) {
            printf("%s\n", student_map[courses[i][j]]);
        }
    }
    return 0;
}