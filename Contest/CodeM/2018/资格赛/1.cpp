/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */


#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100;
int a[SIZE], re[SIZE];
int b[SIZE], c[SIZE];

int main(int argc, char *argv[]) {

    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%d%d", a + i, re + i);
        for (int i = 0; i < m; ++i)scanf("%d%d", b + i, c + i);

        double ans = 0;
        double all_money = 0;
        /*!< all re */
        for (int i = 0; i < n; ++i)
            ans += re[i] ? a[i] * 0.8 : a[i], all_money += a[i];

        for (int i = 0; i < m; ++i)
            if (all_money >= b[i])
                ans = min(ans, all_money - c[i]);
        printf("%.2f\n", ans);

    }
    return 0;
}