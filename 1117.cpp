#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        vec.push_back(d);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (vec[i] <= i + 1) {
            res = i;
            break;
        }
    }
    printf("%d\n", res);

    return 0;
}