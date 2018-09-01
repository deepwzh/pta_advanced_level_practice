#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
void print(char c) {
    switch(c - '0') {
        case 0:
            printf("zero");
            break;
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
    }
}
int main() {
    char s[200];
    scanf("%s", s);
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += s[i] - '0';
    }
    char res[200];
    sprintf(res, "%d", sum);
    int rlen = strlen(res);
    print(res[0]);
    for (int i = 1; i < rlen; i++) {
        printf(" ");
        print(res[i]);
    }
    return 0;
}