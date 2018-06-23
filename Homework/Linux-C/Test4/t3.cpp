/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "t3.h"
#include <iostream>

using namespace std;
int A[] = {1, 23, 4};

int main() {
    try {
        int u[7];
        for (int i = 0; i < 7; ++i)cin >> u[i];
        Array a(A, u[0]);
        a.disp();
        Array b(u[1], 9);
        b.disp();
        a.insert(u[2], 100);
        a.disp();
        a.remove(u[3]);
        a.disp();
        cout << a.at(u[4]) << endl;
        a.modify(u[5], 100);
        a.disp();
        if (u[6] < 0) {
            Array c(1000, 0);
            c.insert(0, 100);
        }
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}

