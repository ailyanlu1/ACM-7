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
    Int b(x);
    Int c(b);
    cout << a.getValue() << " " << b.getValue() << " " << c.getValue() << endl;
    return 0;
}
