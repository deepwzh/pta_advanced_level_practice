#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> vec;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        vec.push_back(d);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < N && vec[i] < M; i++) {
        int a = vec[i];
        int b = M - a;
        vector<int>::iterator low, high;
        low = lower_bound(vec.begin(), vec.end(), b);
        high = upper_bound(vec.begin(), vec.end(), b);
        if (*low != b) continue;
        if (a == b && low + 1 == high) continue;
        printf("%d %d\n", a, b);
        return 0; 
    }
    printf("No Solution\n");
    return 0;
}