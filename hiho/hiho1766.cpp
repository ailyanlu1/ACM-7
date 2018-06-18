/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-18
 */


#include<bits/stdc++.h>

using namespace std;

const int SIZE = 100000 + 500;
int dp[SIZE][30];
char str[SIZE];

void make_DFA(int n) {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)dp[i - 1][str[i - 1] - 'a'] = i;

    for (int i = 0; i < 26; ++i)
        for (int j = n; j >= 0; --j)
            if (dp[j][i] != -1) {
                int k = j - 1;
                while (k >= 0 && dp[k][i] == -1) dp[k--][i] = dp[j][i];
                j = k + 1;
            }
}

int main(int argc, char *argv[]) {
    while (scanf("%s", str) != EOF) {
        auto n = (int) strlen(str);
        make_DFA(n);
//        for (int i = 0; i < n; ++i) { for (int j = 0; j < 26; ++j)cout << dp[i][j] << " ";cout << endl; }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = 0, j = i;
            while (1) {
                idx = dp[idx][str[j] - 'a'];
                if (0 <= idx && idx <= i)j++;
                else break;
            }
            if (i != j)i = j - 1;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}