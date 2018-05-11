//
// Created by bitwater on 18-5-11.
//

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 20;

int ans[SIZE];

int add(char const a[], char const b[]) {
    static int nub1[SIZE];
    static int nub2[SIZE];
    int len1 = strlen(a);
    int len2 = strlen(b);
    static const int P_idx = SIZE / 2;
    int d1_cnt = 0;
    int d2_cnt = 0;
    int d1_idx = len1;
    int d2_idx = len2;
    for (int i = 0; i < len1; ++i) {
        if (a[i] == '.') d1_cnt++, d1_idx = i;
        if ((a[i] < '0' || a[i] > '9') && a[i] != '.') return 0;
    }
    for (int i = 0; i < len2; ++i) {
        if (b[i] == '.') d2_cnt++, d2_idx = i;
        if ((b[i] < '0' || b[i] > '9') && b[i] != '.') return 0;
    }
    if (d1_cnt > 1 || d2_cnt > 1)return 0;
    int tmp = P_idx;
    for (int i = 0; i < d1_idx; ++i)nub1[tmp--] = a[d1_idx - i - 1] - '0';
    tmp = P_idx + 1;
    for (int i = d1_idx + 1; i < len1; ++i)
        nub1[tmp++] = a[i] - '0';
    tmp = P_idx;
    for (int i = 0; i < d2_idx; ++i)nub2[tmp--] = b[d2_idx - i - 1] - '0';
    tmp = P_idx + 1;
    for (int i = d2_idx + 1; i < len2; ++i)nub2[tmp++] = b[i] - '0';
    int al = d1_idx;
    int ar = len1 - d1_idx;
    int bl = d2_idx;
    int br = len2 - d2_idx;
//    for (int i = P_idx - al; i <= P_idx + ar; ++i)cout << nub1[i];cout << endl;
//    for (int i = P_idx - bl; i <= P_idx + br; ++i) cout << nub2[i];cout << endl;

    memset(ans, 0, sizeof(ans));
    for (int i = P_idx + max(ar, br); i >= P_idx - max(al, bl) - 2; --i) {
        ans[i] += nub1[i] + nub2[i];
        ans[i - 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    bool isfir = 1;
    for (int i = P_idx - max(al, bl) - 2; i < P_idx + max(ar, br); ++i) {
        if (isfir && ans[i] == 0) {
            isfir = 0;
            while (ans[i] == 0)i++;
        }
        cout << ans[i];
        if (i == P_idx)cout << '.';
    }
    cout << endl;
    return 1;
}

char str1[SIZE], str2[SIZE];


int main(int argc, char *argv[]) {
    scanf("%s%s", str1, str2);
    bool isok = add(str1, str2);
    if (isok == 0)printf("0\n");
    return 0;
}