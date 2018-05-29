/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t1.h"
#include <iostream>

using namespace std;
int A[] = {100, 200, 400, 800, 1600};

int main() {
    Array a, b(A, 4);
    Array c(b), d(8, 6);
    cout << a.getSize() << " " << b.getSize() << " " << c.getSize() << " " << d.getSize() << endl;
    return 0;
}
