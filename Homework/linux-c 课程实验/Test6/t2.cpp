/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t2.h"
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    Int a(x), b(y);
    Int c = add(a, b);
    Int d = mul(a, b);
    cout << c.getValue() << " " << d.getValue() << endl;
    return 0;
}