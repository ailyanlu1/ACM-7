/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
 */


#include<bits/stdc++.h>

using namespace std;

const int SIZE = 200000 + 500;
char str1[SIZE];
char str2[SIZE];

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n >> str1 >> str2) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (str1[i] == str2[i])continue;
            int j = i;
            while (j < n && str1[j] != str2[j])j++;
            ans++;
            i = j;
        }
        cout << ans << endl;
    }

    return 0;
}