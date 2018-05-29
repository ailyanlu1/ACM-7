/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _INTOP_H_
#define _INTOP_H_

#include "Int.h"
#include <iostream>

/**************************************************
以下为算术运算符重载
**************************************************/

const Int operator+(Int const &lhs, Int const &rhs) {
    return Int(lhs.getValue() + rhs.getValue());
}

const Int operator-(Int const &lhs, Int const &rhs) {
    return Int(lhs.getValue() - rhs.getValue());
}

const Int operator*(Int const &lhs, Int const &rhs) {
    return Int(lhs.getValue() * rhs.getValue());
}

const Int operator/(Int const &lhs, Int const &rhs) {
    return Int(lhs.getValue() / rhs.getValue());
}

const Int operator%(Int const &lhs, Int const &rhs) {
    return Int(lhs.getValue() % rhs.getValue());
}

/**************************************************
以下为关系运算符重载
**************************************************/

bool operator<(Int const &lhs, Int const &rhs) {
    return lhs.getValue() < rhs.getValue();
}

bool operator==(Int const &lhs, Int const &rhs) {
    return lhs.getValue() == rhs.getValue();
}

bool operator<=(Int const &lhs, Int const &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(Int const &lhs, Int const &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(Int const &lhs, Int const &rhs) {
    return !(lhs < rhs);
}

bool operator!=(Int const &lhs, Int const &rhs) {
    return !(lhs == rhs);
}


/**************************************************
以下为流输入输出运算符重载
**************************************************/
std::ostream &operator<<(std::ostream &os, const Int &rhs) {
    os << rhs.getValue();
    return os;
}

std::istream &operator>>(std::istream &is, Int &rhs) {
    int x;
    is >> x;
    rhs.setValue(x);
    return is;
}

#endif // _INTOP_H_