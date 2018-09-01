#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string uname, utime;
    string lname, ltime;
    for (int i = 0; i < n; i++) {
        string name, st, et;
        cin >> name >> st >> et;
        if (utime.empty() || st < utime) {
            utime = st;
            uname = name;
        }
        if (ltime.empty() || et > ltime) {
            ltime = et;
            lname = name;
        }
    }
    cout << uname << " " << lname << endl;
    return 0;
}