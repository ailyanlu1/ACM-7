/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */

#include<bits/stdc++.h>

using namespace std;


//生成组合数
void initC() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j <= i; ++j) {
            if (0 == j || i == j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    //C[0][0] = 1;//此处看情况
}

llt S[SIZE][SIZE];

//第一类斯特林数
//第一类斯特林数s(n,m)定义为有n个人，编号分别为1-n，排成m个循环排列的方案数。
//递推式：s(n,m)=s(n−1,m−1)+(n−1)∗s(n−1,m)
void initStirling1() {
    memset(S, 0, sizeof(S));//慎重memset
    S[1][1] = 1;
    for (int i = 1; i < SIZE; ++i)
        for (int k = 1; k < SIZE; ++k) {
            if (i == 1 && k == 1)continue;
            S[i][k] = (S[i - 1][k - 1] + ((i - 1) * S[i - 1][k]) % MOD) % MOD;
        }
}

//第二类斯特林数
//s(m,n)表示把m个有区别的球放到n个相同的盒子中，且无一空盒，其不同的方案数。
//s(m,n)=ns(m-1,n)+s(m-1,n-1)     (m>=n)
//s(m,n)=0   (m<n)
//s(0,0)=1;

void initStirling2() {
    S[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        S[i][0] = 0;
        for (int j = 1; j <= i; ++j)S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j) % mod;
    }
}
