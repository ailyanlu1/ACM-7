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

class Int {

private://这是访问控制——私有的
    int value; //这是数据成员，我们称Int是基本类型int的包装类，就是因为Int里面只有一个int类型的数据成员

public:    //这是公有的
    //请在以下空白书写构造函数重载，须提供3个构造函数
    /********** Begin **********/

    Int() : value(0) {};

    Int(int x) : value(x) {};

    Int(Int const &b) {
        this->value = b.getValue();
    }

    /********** End **********/

    //请不要改动以下成员函数
    int getValue() const { return value; }

};//记住这里有一个分号

#endif

