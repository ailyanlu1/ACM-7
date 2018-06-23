/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t4.h"
#include <iostream>

#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    Array a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    cout << a << endl;
    cout << b << endl;
    cout << (a == b) << endl;
    cout << (a < b) << endl;
    Array c;
    c = a = a + b;
    cout << c << endl;
    return 0;
}