/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
 */

#include<bits/stdc++.h>

using namespace std;

const int SIZE = 300000 + 400;
char str[3][SIZE];

int main(int argc, char *argv[]) {

    while (scanf("%s%s%s", str[0], str[1], str[2]) != EOF) {
        int n = strlen(str[0]);
        int ans = 0;
        set<char> st;
        for (int i = 0; i < n; ++i) {
            st.clear();
            for (int j = 0; j < 3; ++j)
                st.insert(str[j][i]);
            ans += st.size() - 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}