//
// Created by icebeetle on 18-6-27.
//

#include<bits/stdc++.h>

using namespace std;


const int SIZE = 100000;
int a[SIZE];
int b[SIZE];

int main(int argc, char *argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%d", a + i);
        for (int i = 0; i < n; ++i)b[i] = a[i];

        sort(a, a + n);
        int st = 0, et = n - 1;
        while (st < n && a[st] == b[st])st++;
        while (et >= 0 && a[et] == b[et])et--;
//        printf("%d %d\n", st, et);
        if (st > et)
            printf("0\n");
        else
            printf("%d\n", et - st + 1);
    }
    return 0;
}