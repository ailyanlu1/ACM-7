/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
 */


#include<bits/stdc++.h>

using namespace std;

const int SIZE = 200000 + 500;
int puck[SIZE][3];

int main(int argc, char *argv[]) {

    int n;
    while (cin >> n) {
        int max0 = 0, max1 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> puck[i][0] >> puck[i][1] >> puck[i][2];
            sort(puck[i], puck[i] + 3);
            max0 = max(max0, puck[i][0]);
            max1 = max(max1, puck[i][1]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (puck[i][1] > max0 && puck[i][2] > max1)ans++;
        printf("%d\n", ans);
    }


    return 0;
}