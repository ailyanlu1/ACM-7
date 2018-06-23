/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t2.h"
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    Int a;
    a.setValue(x);
    Int b(a);
    cout << b.getValue() << endl;
    return 0;
}