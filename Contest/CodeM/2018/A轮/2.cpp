/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-9
 */


#include <bits/stdc++.h>

using namespace std;

typedef long long llt;
const int SIZE = 100000 + 50;
llt chess1[SIZE], chess2[SIZE];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%lld", chess1 + i);
        for (int i = 0; i < n; ++i)scanf("%lld", chess2 + i);
        llt ans = 0;
        for (int i = n - 1; i > 0; --i) {
            if (chess1[i] && chess2[i]) {
                llt com = min(chess1[i], chess2[i]);
                chess1[i] -= com;
                chess2[i] -= com;
            }
            if (chess1[i]) {
                ans += chess1[i];
                chess1[i - 1] += chess1[i];
            }
            if (chess2[i])
                ans += chess2[i] * i;
        }
        printf("%lld\n", ans);
    }

    return 0;
}