//
// Created by icebeetle on 18-6-23.
//

#include<bits/stdc++.h>

using namespace std;

const int SIZE = 20000 + 2000;
char str[SIZE];
int sum[SIZE] = {0};


int main(int argc, char *argv[]) {
    for (int i = 1; i < SIZE; ++i)sum[i] = sum[i - 1] + i;

    while (scanf("%s", str) != EOF) {
        int n = strlen(str);
        int idx = 0;
        for (int i = 1; i < n; ++i)
            if (str[i] == '1') {
                idx = i;
                break;
            }

        int ok = 1;
        for (int i = idx + 1; i < n; ++i)if (str[i] == '0')ok = 0;

        if (n == 1)
            printf("%s\n", str);
        else if (idx == 0)
            printf("%d\n", sum[n - 1]);
        else
            printf("%d\n", sum[n - 1] + n - idx - 1 + ok);
    }
    return 0;
}