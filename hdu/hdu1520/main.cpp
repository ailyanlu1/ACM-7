//
// Created by bitwater on 18-5-11.
//

#include <bits/stdc++.h>

using namespace std;
const int SIZE = 10000;

struct edge_t {
    int to;
    int next;
} Edge[SIZE << 1];
int Ver[SIZE];
int Ecnt;
int W[SIZE];
int fa[SIZE];
int dp[SIZE][2];

inline void mkEdge(int a, int b) {
    Edge[Ecnt].to = b;
    Edge[Ecnt].next = Ver[a];
    Ver[a] = Ecnt++;
}

void init() {
    Ecnt = 1;
    memset(Ver, 0, sizeof(Ver));
    memset(fa, 0, sizeof(fa));
}

void dfs(int u) {
    dp[u][0] = 0;
    dp[u][1] = W[u];
    for (int p = Ver[u]; p; p = Edge[p].next) {
        int v = Edge[p].to;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main(int argc, char *argv[]) {
    int n, a, b;
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i <= n; ++i)scanf("%d", W + i);
        while (scanf("%d%d", &a, &b) && (a + b))fa[a] = b;
        for (int i = 1; i <= n; ++i)mkEdge(fa[i], i);
        dfs(0);
        printf("%d\n", max(dp[0][0], dp[0][1]));
    }
    return 0;
}