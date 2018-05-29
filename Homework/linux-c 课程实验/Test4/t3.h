/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdexcept>

using std::invalid_argument;
using std::overflow_error;

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
    Array()throw();//这表示该函数不允许抛出任何异常

    Array(const Array &rhs)noexcept;//同上
    //以下2个构造函数有可能抛出一个invalid_argument异常
    Array(int const a[], int n)noexcept(false);

    Array(int count, int value)noexcept(false);
    /**增删查改*/
    //pos位置上插入一个值为value的元素，pos及其后面的元素依次后移
    //该函数有可能抛出2种异常，非法参数或者溢出
    void insert(int pos, int value)noexcept(false);

    //删除pos位置上的元素，其后的元素依次前移
    void remove(int pos)noexcept(false);

    //返回第pos个位置上的元素值
    int at(int pos) const noexcept(false);

    //将pos位置上的元素值修改为newValue
    void modify(int pos, int newValue)noexcept(false);

    //显示函数，将数组内容显示输出为一行，且每一个数后面均有一个空格
    void disp() const noexcept;
};

#endif // _ARRAY_H_


#include <cstdio>

Array::Array(const Array &rhs)noexcept {
    this->size = rhs.size;
    for (int i = 0; i < this->size; ++i)
        this->data[i] = rhs.at(i);
}


Array::Array() noexcept {
    this->size = 0;
}

Array::Array(const int a[], int n) noexcept(false) {
    if (n > SIZE || n < 0)
        throw invalid_argument(__func__);
    this->size = n;
    for (int i = 0; i < n; ++i)
        this->data[i] = a[i];
}

Array::Array(int count, int value) noexcept(false) {
    if (count > SIZE || count < 0)
        throw invalid_argument(__func__);
    this->size = count;
    for (int i = 0; i < count; ++i)
        this->data[i] = value;

}

void Array::insert(int pos, int value)noexcept(false) {
    if (this->size == SIZE)throw overflow_error(__func__);
    if (pos < 0 || pos >= size)throw invalid_argument(__func__);
    for (int i = this->size; i > pos; --i)
        this->data[i] = this->data[i - 1];
    this->data[pos] = value;
    this->size++;

}

void Array::remove(int pos)noexcept(false) {
    if (pos < 0 || pos >= size)throw invalid_argument(__func__);
    for (int i = pos; i < this->size - 1; ++i)
        this->data[i] = this->data[i + 1];
    this->size--;
}

int Array::at(int pos) const noexcept(false) {
    if (pos < 0 || pos >= size)throw invalid_argument(__func__);
    return this->data[pos];
}

void Array::modify(int pos, int newValue) noexcept(false) {
    if (pos < 0 || pos >= size)throw invalid_argument(__func__);
    this->data[pos] = newValue;
}

void Array::disp() const noexcept {
    for (int i = 0; i < this->size; ++i)
        printf("%d ", this->data[i]);
    printf("\n");
}
