/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _ARRAY_H_
#define _ARRAY_H_

class Array {
private:
    enum {
        SIZE = 1000
    };//该枚举的作用是规定原生数组的尺寸
    int data[SIZE];  //被包装的原生数组，可称之为数据的容器
    int size;        //当前数组的实际元素个数
public:
    int getSize() const { return size; }

    //默认构造函数
    Array();

    //拷贝构造函数
    Array(const Array &rhs);

    //原生数组构造函数，a表示原生数组，n表示a中元素的个数
    Array(int const a[], int n);

    //填充构造函数，表示该数组由n个value构成
    Array(int count, int value);
};

#endif // _ARRAY_H_


Array::Array() {
    this->size = 0;
}

Array::Array(const Array &rhs) {
    this->size = rhs.getSize();
}

Array::Array(const int *a, int n) {
    this->size = n;
}

Array::Array(int count, int value) {
    this->size = count;
}
