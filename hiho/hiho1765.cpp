/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */

#include<bits/stdc++.h>

typedef long long llt;
using namespace std;

const int SIZE = 200;
int a[SIZE], b[SIZE];
int ha[SIZE], hb[SIZE];
int overa[SIZE], overb[SIZE];
int fac[13] = {1};

int A(int n, int m) {
    return fac[n] / fac[n - m];
}

int main() {
    for (int i = 1; i < 13; ++i)fac[i] = i * fac[i - 1];

    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%d", a + i);
        for (int i = 0; i < n; ++i)scanf("%d", b + i);
        memset(ha, 0, sizeof(ha));
        memset(hb, 0, sizeof(hb));
        memset(overa, 0, sizeof(overa));
        memset(overb, 0, sizeof(overb));
        for (int i = 0; i < n; ++i)ha[a[i]]++, hb[b[i]]++;
        for (int i = 100; i >= 1; --i) overa[i] = ha[i] + overa[i + 1], overb[i] = hb[i] + overb[i + 1];
        int ans = 1;
        for (int i = 100; i >= 1; --i)
            if (ha[i]) {
                if (overb[i] - overa[i + 1] >= ha[i])
                    ans *= A(overb[i] - overa[i + 1], ha[i]);
                else ans = 0;
            }
        printf("%lld\n", ans);
    }
    return 0;
}
