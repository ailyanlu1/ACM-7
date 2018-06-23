/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _ARRAYLISTOP_H_
#define _ARRAYLISTOP_H_

//#include "t4.h"
#include <iostream>
#include <algorithm>

using namespace std;

//加号运算符重载，加法实现连接功能
const ArrayList operator+(const ArrayList &lhs, const ArrayList &rhs) {
    ArrayList ret;
    for (int i = 0; i < lhs.getSize(); ++i)
        ret.insert(ret.getSize(), lhs.at(i));

    for (int i = 0; i < rhs.getSize(); ++i)
        ret.insert(ret.getSize(), rhs.at(i));
    return ret;
}

//关系运算符重载，按照字典序比较顺序表
bool operator==(const ArrayList &lhs, const ArrayList &rhs) {
    if (lhs.getSize() != rhs.getSize()) return 0;
    for (int i = 0; i < rhs.getSize(); ++i)
        if (lhs.at(i) != rhs.at(i))return 0;
    return 1;
}

bool operator!=(const ArrayList &lhs, const ArrayList &rhs) {
    return !(lhs == rhs);
}

bool operator<(const ArrayList &lhs, const ArrayList &rhs) {
    for (int i = 0; i < min(lhs.getSize(), rhs.getSize()); ++i)
        if (lhs.at(i) != rhs.at(i))return lhs.at(i) < rhs.at(i);
    return lhs.getSize() < rhs.getSize();
}

bool operator<=(const ArrayList &lhs, const ArrayList &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(const ArrayList &lhs, const ArrayList &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const ArrayList &lhs, const ArrayList &rhs) {
    return !(lhs < rhs);
}
//流输出运算符重载，所有内容输出一行，每个数据后面接一个空格
using std::ostream;

ostream &operator<<(ostream &os, const ArrayList &rhs) {
    for (int i = 0; i < rhs.getSize(); ++i)
        os << rhs.at(i) << " ";
    return os;
}

#endif // _ARRAYLISTOP_H_