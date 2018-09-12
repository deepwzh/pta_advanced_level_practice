/**
 * 题目对内存空间卡的比较严格，我这里采取的存入第一组数据后，第二组数据不存，边用边读
 * 详细思路见代码
 */
#include <cstdio>
using namespace std;
int A[100000 * 2 + 10];
int cntb = 0;
int get_next_num(int n) {
    if (cntb < n) {
        int d;
        scanf("%d",&d);
        cntb++;
        return d;
    } else {
        return -1;
    }
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int d;
        scanf("%d", &d);
        A[i] = d;
        // sets.insert(d);
    }
    scanf("%d", &n2);
    int cnt = 0;
    int len = n1 + n2;
    int p1 = 0, p2 = 0;
    int res = 0;
    int res0 = 0;
    int last_b_num = -1;
    if (n2) {
        last_b_num = get_next_num(n2);
    }
    while (p1 < n1 && p2 < n2) {
        int d = 0;
        if (A[p1] < last_b_num) {
            d = A[p1];
            p1++;
        } else {
            d = last_b_num;
            last_b_num = get_next_num(n2);
            p2++;
        }
        if ((((len + 1) / 2) - 1) == cnt) {
            res = d;
        }
        cnt++;
    }
    if (res != 0) {
        if (len % 2 == 1) {
            printf("%d\n", res);
        } else {
            printf("%d\n", res);
        }
    } else {
        while (p1 < n1) {
            if ((((len + 1) / 2) - 1) == cnt) {
                res = A[p1];
            }
            p1++;
            cnt++;
        }
        while (p2 < n2) {
            if ((((len + 1) / 2) - 1) == cnt) {
                res = last_b_num;
                last_b_num = get_next_num(n2);
            }
            p2++;
            cnt++;
        }
        if (len % 2 == 1) {
            printf("%d\n", res);
            return 0;
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}