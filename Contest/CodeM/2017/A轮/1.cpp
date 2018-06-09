/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-9
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long llt;

int n, t, c;
llt T, C;

int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%lld%lld", &T, &C);
        llt totv = C, totf = T * C;
        int maxt = 0, mint = 11000;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &t, &c);
            if (c)maxt = max(maxt, t);
            if (c)mint = min(mint, t);
            totf += t * c;
            totv += c;
        }
        if (T < mint) {
            if (totf <= mint * totv)printf("Possible\n%.4f\n", (double) mint);
            else printf("Impossible\n");
        } else if (mint < T && T < maxt) {
            printf("Impossible\n");
        } else {
            if (totf >= maxt * totv)printf("Possible\n%.4f\n", totf / (double) totv);
            else printf("Impossible\n");
        }
    }
    return 0;
}