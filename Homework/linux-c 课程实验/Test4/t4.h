/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

class Array {
private:
    enum {
        SIZE = 1000
    };//该枚举的作用是规定原生数组的尺寸
    int data[SIZE];  //被包装的原生数组，可称之为数据的容器
    int size;        //当前数组的实际元素个数
public:
    int getSize() const { return size; }

    //4个构造函数
    Array();

    Array(const Array &rhs);

    Array(int const a[], int n);

    Array(int count, int value);
    /**增删查改*/
    //pos位置上插入一个值为value的元素，pos及其后面的元素依次后移
    void insert(int pos, int value);

    //删除pos位置上的元素，其后的元素依次前移
    void remove(int pos);

    //返回第pos个位置上的元素值
    int at(int pos) const;

    //将pos位置上的元素值修改为newValue
    void modify(int pos, int newValue);

    //显示函数，将数组内容显示输出为一行，且每一个数后面均有一个空格
    void disp() const;

    //简单赋值运算符重载
    Array &operator=(const Array &rhs);

    //方括号运算符重载
    int &operator[](int pos);

    const int &operator[](int pos) const;
};

//小于号运算符重载
bool operator<(const Array &lhs, const Array &rhs);

//等于号运算符重载
bool operator==(const Array &lhs, const Array &rhs);

//加号运算符重载
const Array operator+(const Array &lhs, const Array &rhs);
//流输出运算符重载
using std::ostream;

ostream &operator<<(ostream &os, const Array &rhs);

#endif // _ARRAY_H_


#include <cstdio>
#include <algorithm>

using namespace std;

Array::Array(const Array &rhs) {
    this->size = rhs.size;
    for (int i = 0; i < this->size; ++i)
        this->data[i] = rhs.at(i);
}


Array::Array() {
    this->size = 0;
}

Array::Array(const int *a, int n) {
    this->size = n;
    for (int i = 0; i < n; ++i)
        this->data[i] = a[i];

}

Array::Array(int count, int value) {
    this->size = count;
    for (int i = 0; i < count; ++i)
        this->data[i] = value;

}

void Array::insert(int pos, int value) {
    for (int i = this->size; i > pos; --i)
        this->data[i] = this->data[i - 1];
    this->data[pos] = value;
    this->size++;
}

void Array::remove(int pos) {
    for (int i = pos; i < this->size - 1; ++i)
        this->data[i] = this->data[i + 1];
    this->size--;
}

int Array::at(int pos) const {
    return this->data[pos];
}

void Array::modify(int pos, int newValue) {
    this->data[pos] = newValue;
}

void Array::disp() const {
    for (int i = 0; i < this->size; ++i)
        printf("%d ", this->data[i]);
    printf("\n");
}

Array &Array::operator=(const Array &rhs) {
    this->size = rhs.getSize();
    for (int i = 0; i < this->size; ++i)
        this->data[i] = rhs.at(i);
    return *this;
}

int &Array::operator[](int pos) {
    return this->data[pos];
}

const int &Array::operator[](int pos) const {
    return this->data[pos];;
}

//小于号运算符重载
bool operator<(const Array &lhs, const Array &rhs) {
//    if (lhs.getSize() != rhs.getSize())return lhs.getSize() < rhs.getSize();
    for (int i = 0; i < min(rhs.getSize(), lhs.getSize()); ++i) {
        if (lhs.at(i) != rhs.at(i)) return lhs.at(i) < rhs.at(i);
    }
    return lhs.getSize() < rhs.getSize();
}

//等于号运算符重载
bool operator==(const Array &lhs, const Array &rhs) {
    if (lhs.getSize() != rhs.getSize())return 0;
    for (int i = 0; i < rhs.getSize(); ++i) {
        if (lhs.at(i) != rhs.at(i)) return 0;
    }
    return 1;
}

//加号运算符重载
const Array operator+(const Array &lhs, const Array &rhs) {
    Array ret;
    for (int i = 0; i < lhs.getSize(); ++i)
        ret.insert(ret.getSize(), lhs.at(i));
    for (int i = 0; i < rhs.getSize(); ++i)
        ret.insert(ret.getSize(), rhs.at(i));
    return ret;
}
//流输出运算符重载
using std::ostream;

ostream &operator<<(ostream &os, const Array &rhs) {
    for (int i = 0; i < rhs.getSize(); ++i) {
        os << rhs.at(i) << " ";
    }
    return os;
}