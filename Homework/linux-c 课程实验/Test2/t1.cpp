/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t1.h"
#include <iostream>

using namespace std;

int main() {
    Int a, b;
    int x;
    cin >> x;
    a.setValue(x);
    b = a;
    cout << b.getValue() << endl;
    return 0;
}