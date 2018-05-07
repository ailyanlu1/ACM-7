//
// Created by bitwater on 18-5-7.
//

#include"../../headers.h"

char str[1000000];

int cal1() {
    int len = strlen(str);
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9')ret = str[i] - '0';
        else {
            if (str[i] == '+')ret += str[i + 1] - '0';
            else ret *= str[i + 1] - '0';
            i++;
        }

    }
    return ret;
}

inline int tr(char ch) {
    return ch == '*' ? 2 : 1;
}

int cal2() {
    stack<int> oper, nub;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9')nub.push(str[i] - '0');
        else {
            if (oper.empty()) oper.push(tr(str[i]));
            else {
                while (!oper.empty() && tr(str[i]) <= oper.top()) {
                    int o = oper.top();oper.pop();
                    int x = nub.top();nub.pop();
                    int y = nub.top();nub.pop();
                    if (o == 1)
                        nub.push(x + y);
                    else
                        nub.push(x * y);
                }
                oper.push(tr(str[i]));
            }
        }
    }
    while (!oper.empty()) {
        int o = oper.top();oper.pop();
        int x = nub.top();nub.pop();
        int y = nub.top();nub.pop();
        if (o == 1)
            nub.push(x + y);
        else
            nub.push(x * y);
    }
    return nub.top();

}

int main() {
    while (scanf("%s", str) != EOF) {
        int x;scanf("%d", &x);
        int t2 = cal1();
        int t1 = cal2();
        if (t1 == x && t2 != x)printf("M\n");
        if (t1 != x && t2 == x)printf("L\n");
        if (t1 == x && t2 == x)printf("U\n");
        if (t1 != x && t2 != x)printf("I\n");
    }
    return 0;
}
