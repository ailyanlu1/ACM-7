/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */

#include<bits/stdc++.h>

using namespace std;
typedef long long llt;

int main(int argc, char *argv[]) {
    int n, x;
    while (scanf("%d", &n) != EOF) {
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            tmp ^= x;
        }
        if (tmp)printf("0\n");
        else {
            llt ans = 1;
            while (n--) ans *= 2LL;
            printf("%lld\n", ans - 2);
        }
    }
    return 0;
}