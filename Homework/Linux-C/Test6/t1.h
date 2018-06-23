/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
/**
 * 这是一个包装类(wrapper class)，包装类在C++中有点小小的用处(基本上没用)，在Java中的用处更大一些。
 */
#ifndef _INT_H_  //这是define guard
#define _INT_H_  //在C和C++中，头文件都应该有这玩意

#include <iostream>

using namespace std;

class Int {
private://这是访问控制——私有的
    int value; //这是数据成员，我们称Int是基本类型int的包装类，就是因为Int里面只有一个int类型的数据成员
public:    //这是公有的
    Int() : value(0) {}

    Int(Int const &rhs) : value(rhs.value) {}

    Int(int v) : value(v) {}

    int getValue() const { return value; }
};//记住这里有一个分号
//注意这里有一个函数声明，也就是需要实现的函数
//一般而言，这个函数声明应该写在另一个头文件中，如IntOp.h
void output(Int const &tt) {
    cout << tt.getValue() << endl;
}

#endif