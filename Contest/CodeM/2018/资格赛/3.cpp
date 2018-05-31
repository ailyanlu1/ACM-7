/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */

#include <bits/stdc++.h>

using namespace std;

double mat[20][20];

double team[20][5];

inline int revbit(int x, int pos) {
    return x ^ (1 << pos);
}

int main(int argc, char *argv[]) {

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            scanf("%lf", &mat[i][j]);

    for (int i = 0; i < 16; ++i)team[i][0] = 1;

    for (int k = 1; k <= 4; ++k) {
        for (int i = 0; i < 16; ++i) {
            double tmp = 0;
            int st = revbit(i, k - 1) >> (k - 1) << (k - 1);
//            printf("%d == st:%d(%d)\n", i, st, (1 << (k - 1)));
            for (int j = 0; j < (1 << (k - 1)); ++j)
                tmp += mat[i][j + st] * team[j + st][k - 1];
            team[i][k] = team[i][k - 1] * tmp;
        }
    }
    for (int i = 0; i < 15; ++i)
        printf("%.10f ", team[i][4]);
    printf("%.10f\n", team[15][4]);

    return 0;
}