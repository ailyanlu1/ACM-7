/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t4.h"
#include "t4op.h"

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    ArrayList a(n, 0), b(m, 0), c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    c = a += b;
    cout << (a == b) << " " << (a != b) << " " << (a < b) << " " << (a <= b) << " " << (a > b) << " " << (a >= b)
         << endl;
    cout << (a == c) << " " << (a != c) << " " << (a < c) << " " << (a <= c) << " " << (a > c) << " " << (a >= c)
         << endl;
    cout << (b == c) << " " << (b != c) << " " << (b < c) << " " << (b <= c) << " " << (b > c) << " " << (b >= c)
         << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}

