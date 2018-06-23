/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t4.h"
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    Int a(x), b(y);
    a += b;
    cout << a.getValue() << " " << b.getValue() << endl;
    return 0;
}

