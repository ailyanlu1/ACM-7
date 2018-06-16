/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-16
 */

#include<bits/stdc++.h>

using namespace std;

int ha[10];

bool get(int to, int &x) {
    bool ret = 0;
    for (int i = to; i >= 0; --i)
        if (ha[i]) {
            ha[i]--, x = i, ret = 1;
            break;
        }
    return ret;
}

int a[4];

bool set2() {
    if (a[0] == 0 || a[0] == 1)return get(9, a[1]);
    else if (a[2] == 2)return get(3, a[1]);
    return 0;
}


int main() {
    while (scanf("%d%d%d%d", a, a + 1, a + 2, a + 3) != EOF) {
        memset(ha, 0, sizeof(ha));
        for (int i : a)ha[i]++;
        if (get(2, a[0]) && set2() && get(5, a[2]) && get(9, a[3]))
            printf("%d%d:%d%d\n", a[0], a[1], a[2], a[3]);
        else
            printf("NOT POSSIBLE\n");
    }
    return 0;
}