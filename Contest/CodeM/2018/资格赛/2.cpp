/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */

 #include <bits/stdc++.h>

using namespace std;

const int SIZE = 10000 + 50;

struct _t {
    int a, b, id;
    double op;

    friend bool operator<(const _t &a, const _t &b) {
        return a.op < b.op;
    }
};

_t cola[SIZE];

int main(int argc, char *argv[]) {
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &cola[i].a, &cola[i].b);
            cola[i].id = i;
            cola[i].op = (double) m / n * cola[i].a + (double) (n - m) / n * cola[i].b;
        }
        sort(cola, cola + k);
//        for (int i = 0; i < k; ++i)cout << cola[i].op << " " << cola[i].id << endl;
        for (int i = 0; i < k; ++i) {
            if (i == cola[k - 1].id)printf("%d",n);
            else printf("0");
            if (i != k - 1)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}