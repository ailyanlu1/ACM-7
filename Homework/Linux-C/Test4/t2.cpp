/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t2.h"
#include <iostream>

using namespace std;

int main() {
    int n, x;
    Array a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.insert(a.getSize(), x);
    }
    a.disp();
    for (int i = 0; i < 3 && a.getSize() != 0; ++i) {
        a.remove(0);
    }
    a.disp();
    for (int i = 0; i < a.getSize(); i += 2) {
        a.modify(i, a.at(i) * 10);
    }
    a.disp();
    return 0;
}
