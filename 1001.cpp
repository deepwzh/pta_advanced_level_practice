    #include <cstdio>
    #include <string>
    #include <iostream>
    #include <cstdlib>
    #include <cstring>
    using namespace std;
    int main() {
        string s;
        int a, b, d;
        scanf("%d%d", &a, &b);
        d = a + b;
        bool is_neg = false;
        if (d < 0) {
            is_neg = true;
            d = - d;
        }
        int pos = 0;
        while (d) {
            char t[2];
            sprintf(t, "%d", d % 10);
            if (pos && pos%3==0) {
                s.insert(0, ",");
            }
            s.insert(0, t);
            pos++;
            d /= 10;
        }
        if (is_neg) {
            cout << "-";
        }
        if (!s.length()) {
            cout << 0 << endl;
        } else {
            cout << s << endl;
        }

        // a.append("bbb");
        // cout << a << endl;
        return 0;
    }
    // #include <cstdio>
    // #include <string>
    // using namespace std;
    // string format(int d) {
    //     string s;
    //     while(d) {
    //         s = s + s.insert(0, d % 10);
    //         d /= 10;
    //     }
    //     return s;
    // }
    // int main() {
    //     int a, b;
    //     scanf("%d%d", &a, &b);
    //     printf("%s\n", format(a + b));
    //     return 0;
    // }