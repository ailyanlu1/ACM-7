//
// Created by bitwater on 18-5-11.
//

#include <bits/stdc++.h>

using namespace std;

int ans;


const int SIZE = 10000;
char str1[SIZE];
char str2[SIZE];

char str3[SIZE];

int cal(int n) {
    static int nubl[10];
    static int nubr[10];
    memset(nubl, -1, sizeof(nubl));
    memset(nubr, -1, sizeof(nubr));
    for (int i = 0; i < n; ++i) {
        int x = str3[i] - '0';
        if (nubl[x] == -1) nubl[x] = i;
        else nubl[x] = min(nubl[x], i);
        if (nubr[x] == -1) nubr[x] = i;
        else nubr[x] = max(nubr[x], i);
    }
    int ret = 0;
    for (int i = 0; i < 10; ++i)ret += nubl[i] - nubr[i];
    return ret;
}

int len1, len2;

void dfs(int li, int ri) {
    if (li >= len1 && ri >= len2) {
        ans = min(ans, cal(li + ri));
        return;;
    }
    if (li >= len1) {
        str3[li + ri] = str2[ri];
        dfs(li, ri+1);
        return;
    } else if (ri >= len2) {
        str3[li + ri] = str1[li];
        dfs(li+1, ri);
        return;
    } else {
        str3[li + ri] = str1[li];
        dfs(li + 1, ri);
        str3[li + ri] = str2[ri];
        dfs(li, ri + 1);
    }
}

int main(int argc, char *argv[]) {

    ans = INT_MAX;
    scanf("%s%s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}