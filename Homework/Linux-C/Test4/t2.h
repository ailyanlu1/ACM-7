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
};

#endif // _ARRAY_H_

#include <cstdio>

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
