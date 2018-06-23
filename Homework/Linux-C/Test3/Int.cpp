/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#include "Int.h"
#include "op.h"
#include <iostream>

using namespace std;

int main() {
    Int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    cout << (a + b) << " " << (a - b) << " " << (a * b) << " " << (a / b) << " " << (a % b) << endl;
    if (a < b) cout << a << " is less than " << b << "." << endl;
    else cout << a << " is NOT less than " << b << "." << endl;
    if (a <= b) cout << a << " is less than or equal to " << b << "." << endl;
    else cout << a << " is NOT less than or equal to " << b << "." << endl;
    if (a > b) cout << a << " is greater than " << b << "." << endl;
    else cout << a << " is NOT greater than " << b << "." << endl;
    if (a >= b) cout << a << " is greater than or equal to " << b << "." << endl;
    else cout << a << " is NOT greater than or equal to " << b << "." << endl;
    if (a == b) cout << a << " is equal to " << b << "." << endl;
    else cout << a << " is NOT equal to " << b << "." << endl;
    if (a != b) cout << a << " is not equal to " << b << "." << endl;
    else cout << a << " is NOT not equal to " << b << "." << endl;
    cout << ++a << " " << --b << endl;
    cout << a << " " << b << endl;
    cout << a++ << " " << b-- << endl;
    cout << a << " " << b << endl;
    cout << (a += b) << endl;
    cout << (a -= b) << endl;
    cout << (a *= b) << endl;
    cout << (a /= b) << endl;
    cout << (a %= b) << endl;
    return 0;
}