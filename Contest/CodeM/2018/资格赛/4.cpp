/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */


#include <bits/stdc++.h>

using namespace std;

struct _t {
    int id;
    double score;

    _t(int ii = 0, double ss = 0) : id(ii), score(ss) {};

    friend bool operator<(const _t &a, const _t &b) {
        return a.score < b.score;
    }
};

const int SIZE = 1100;
_t per[SIZE];
double maxscore[10], mat[SIZE][10], w[10];
int ans[SIZE];
int xi, yi;
int n, m, k, c;
double const eps = 1e-8;

void update(_t per[], int v) {
    mat[xi][yi] = v;
    memset(maxscore, 0, sizeof(maxscore));
    for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)maxscore[j] = max(maxscore[j], mat[i][j]);

    for (int i = 0; i < n; ++i) {
        double tmp = 0;
        for (int j = 0; j < m; ++j)if (maxscore[j] > eps)tmp += mat[i][j] / maxscore[j] * w[j];
        per[i] = _t(i, tmp);
    }
}


int main() {

    while (scanf("%d%d%d%d", &n, &m, &k, &c) != EOF) {

        w[m] = 0;
        for (int i = 0; i < m; ++i)scanf("%lf", w + i);
        for (int i = 0; i < m; ++i)w[m] += w[i];
        for (int i = 0; i < m; ++i)w[i] /= w[m];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%lf", &mat[i][j]);
                if (mat[i][j] == -1)xi = i, yi = j;
            }

        if (n == k) {
            for (int i = 0; i < n; ++i)printf("1\n");
            continue;
        }
        if (0 == k) {
            for (int i = 0; i < n; ++i)printf("2\n");
            continue;
        }
        memset(ans, 0, sizeof(ans));

        for (int v = 0; v <= c; ++v) {

            update(per, v);
//            for (int i = 0; i < n; i++)printf("%.3f\n", per[i].score);printf("\n\n");

            sort(per, per + n);
            for (int i = n - 1; i >= n - k; --i)
                if (per[i].score > per[n - k - 1].score)ans[per[i].id]++;

            for (int i = 0; i < n - k; ++i)
                if (per[i].score < per[n - k].score)ans[per[i].id]--;
        }
        c++;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == c)printf("1\n");
            if (ans[i] == -c)printf("2\n");
            if (ans[i] != -c && ans[i] != c)printf("3\n");
        }
    }

    return 0;
}