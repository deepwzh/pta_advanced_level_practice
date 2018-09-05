#include <cstdio>
#include <string>
#include <vector>
using namespace std;
vector<int> d2x(int N, int radix) {
    vector<int> vec;
    if (!N) {
        vec.push_back(0);
    }
    while (N) {
        vec.push_back(N % radix);
        N /= radix;
    }
    return vec;
}
bool is_palindromic(vector<int> num) {
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int N, b;
    scanf("%d%d", &N, &b);
    vector<int> vec = d2x(N, b);
    if (is_palindromic(vec)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("%d", vec[vec.size() - 1]);
    if (vec.size() > 1) {
        for (int i = vec.size() - 2; i >= 0; i--) {
            printf(" %d", vec[i]);
        }
    }
    printf("\n");
    return 0;
}