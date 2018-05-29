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
    int value_; //这是数据成员，Google风格要求成员变量的名字以下划线结尾

public:    //这是公有的
    //请在以下空白填写成员变量value的存取函数，按照Google C++风格命名
    //即，存函数命名为set_value，取函数命名为value
    /********** Begin **********/
    void set_value(int x) {
        this->value_ = x;
    }

    int value() const {
        return this->value_;
    }

    /********** End **********/

};//记住这里有一个分号

#endif

