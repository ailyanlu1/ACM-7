//
// Created by icebeetle on 18-6-23.
//

#include<bits/stdc++.h>

using namespace std;

struct _t {
    int x, y, z, t;

    explicit _t(int xx = 0, int yy = 0, int zz = 0, int tt = 0) : x(xx), y(yy), z(zz), t(tt) {};

    friend bool operator<(const _t &a, const _t &b) {
        return a.t < b.t;
    }
};

const int SIZE_T = 200000;
const int SIZE = 510;
_t peo[SIZE_T];


inline int read_t(int a, int b, int c, int d) {
    return (a * 60 * 60 + b * 60 + c) * 1000 + d;
}

int chess[SIZE][SIZE];

int main(int argc, char *argv[]) {
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < k; ++i) {
            int x, y, z, a, b, c, d;
            scanf("%d%d%d%d:%d:%d.%d", &x, &y, &z, &a, &b, &c, &d);
            peo[i] = _t(x - 1, y - 1, z, read_t(a, b, c, d));
        }
        sort(peo, peo + k);
        int cnt = 0;
        int mcnt = 0;
        int ansid = -1;
        memset(chess, 0, sizeof(chess));
        for (int i = 0; i < k; ++i) {
            if (peo[i].z == 0) {
                if (chess[peo[i].x][peo[i].y] == 0) cnt++;
                chess[peo[i].x][peo[i].y]++;
            } else {
                if (chess[peo[i].x][peo[i].y] == 1) cnt--;
                chess[peo[i].x][peo[i].y]--;
            }
            if (mcnt <= cnt) {
                mcnt = cnt;
                ansid = i;
            }
        }
        memset(chess, 0, sizeof(chess));
        for (int i = 0; i <= ansid; ++i) {
            if (peo[i].z == 0) {
                if (chess[peo[i].x][peo[i].y] == 0) cnt++;
                chess[peo[i].x][peo[i].y]++;
            } else {
                if (chess[peo[i].x][peo[i].y] == 1) cnt--;
                chess[peo[i].x][peo[i].y]--;
            }

        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)printf(chess[i][j] ? "1" : "0");
            printf("\n");
        }
    }
    return 0;
}