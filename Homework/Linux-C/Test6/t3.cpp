/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t3.h"

#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    Int a(x), b(y), c, d;
    add(a, b, c);
    mul(a, b, d);
    cout << c.getValue() << " " << d.getValue() << endl;
    return 0;
}