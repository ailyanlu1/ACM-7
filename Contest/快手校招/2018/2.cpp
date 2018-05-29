//
// Created by bitwater on 18-5-10.
//

/*!<
 * 水题 sg函数, 一堆石子, 每次一定要取2的n次方个, 取最后的一个石子的赢, 问先取能不能赢
 *
 * */

#include<bits/stdc++.h>

using namespace std;
const int SIZE = 10000 + 300;
int dp[SIZE];

int dfs(int x) {
    if (dp[x] != -1)return dp[x];
    int ret = 0;
    for (int i = 1; i <= x; i <<= 1)
        if (dfs(x - i) == 0 || i == x)ret = 1;
    return dp[x] = (ret == 1);
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf(dfs(n) ? "lucky\n" : "don't be discouraged\n");
    }
    return 0;
}