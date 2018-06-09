/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-9
 */


#include <bits/stdc++.h>

int dis[30][30];
int ingroup[30];
int group[10][10];


void init() {
    for (int i = 0; i < 30; ++i)dis[i][i] = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = i; j < 9; ++j) {
            int tmp;
            if (i == j)tmp = 0;
            if (i + 1 == j) {
                if (i == 2 || i == 5 || i == 8)tmp = 3;
                else tmp = 1;
            }
            if (i + 2 == j)tmp = 2;
            if (i + 3 == j) tmp = 1;
            if (i + 4 == j) {
                if (i == 2)tmp = 4;
                else tmp = 2;
            }
            if (i + 5 == j)tmp = 3;
            if (i + 6 == j)tmp = 2;
            if (i + 7 == j)tmp = 3;
            if (i + 8 == j)tmp = 4;
            group[i][j] = group[j][i] = tmp;
        }
    }
//    for (int i = 0; i < 9; ++i) {for (int j = 0; j < 9; ++j)cout << group[i][j] << " ";cout << endl;}
    int idx = 0;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 1;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 2;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 3;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 4;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 5;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = ingroup[idx + 3] = 6;
    idx += 4;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = 7;
    idx += 3;
    ingroup[idx] = ingroup[idx + 1] = ingroup[idx + 2] = ingroup[idx + 3] = 8;
    idx += 4;
//    cout << idx << endl;
}

const int SIZE = 100000 + 50;
char str[SIZE];

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", str);
        int ans = 0;
        int lastg = 0;
        for (int i = 0; str[i]; ++i) {
            ans += group[lastg][ingroup[str[i] - 'A']];
            lastg = ingroup[str[i] - 'A'];
        }
        printf("%d\n", ans);
    }

    return 0;
}