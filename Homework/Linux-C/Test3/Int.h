/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _INT_H_
#define _INT_H_

class Int {
private:
    int value;
public:
    /*************************************
    以下为构造函数和析构函数
    *************************************/
    Int();//默认构造函数
    Int(const Int &rhs);//拷贝构造函数
    Int(int v);//其他功能构造函数
    ~Int();//析构函数
    /*************************************
    以下为存取函数
    *************************************/
    int getValue() const;

    void setValue(int v);

    /*************************************
    以下为以成员函数形式重载的赋值运算符
    *************************************/
    Int &operator=(const Int &rhs);//拷贝赋值运算符
    Int &operator+=(const Int &rhs);//复合赋值运算符
    Int &operator-=(const Int &rhs);//复合赋值运算符
    Int &operator*=(const Int &rhs);//复合赋值运算符
    Int &operator/=(const Int &rhs);//复合赋值运算符
    Int &operator%=(const Int &rhs);//复合赋值运算符
    /****************************************
    以下为以成员函数形式重载的自增自减运算符
    *****************************************/
    Int &operator++();//前缀自增运算符
    Int &operator--();//前缀自减运算符
    /*注意后缀运算符与前缀运算符的区别，返回类型和参数*/
    const Int operator++(int tmp);//后缀自增运算符
    const Int operator--(int tmp);//后缀自减运算符
};

Int::Int() {

}

Int::Int(const Int &rhs) {
    this->value = rhs.getValue();
}

Int::Int(int v) {
    this->value = v;
}

Int::~Int() {

}

int Int::getValue() const {
    return this->value;
}

void Int::setValue(int v) {
    this->value = v;
}

Int &Int::operator+=(const Int &rhs) {
    this->value += rhs.getValue();
    return *this;
}

Int &Int::operator=(const Int &rhs) {
    this->value = rhs.getValue();
    return *this;
}

Int &Int::operator-=(const Int &rhs) {
    this->value -= rhs.getValue();
    return *this;

}

Int &Int::operator*=(const Int &rhs) {
    this->value *= rhs.getValue();
    return *this;

}

Int &Int::operator/=(const Int &rhs) {
    this->value /= rhs.getValue();
    return *this;

}

Int &Int::operator%=(const Int &rhs) {
    this->value %= rhs.getValue();
    return *this;
}

Int &Int::operator++() {
    this->value++;
    return *this;
}

Int &Int::operator--() {
    this->value--;
    return *this;
}

const Int Int::operator++(int tmp) {
    tmp = this->value++;
    return Int(tmp);
}

const Int Int::operator--(int tmp) {
    tmp = this->value--;
    return Int(tmp);
}

#endif // _INT_H_
