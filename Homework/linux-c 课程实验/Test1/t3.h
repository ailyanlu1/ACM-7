/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */

#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <stdexcept>

using std::invalid_argument;
using std::bad_alloc;

class ArrayList {
private:
    int *data;   //真正保存数据的地方
    int size;    //数据的数量
    int capacity;//容量

public:
    //默认构造函数，构造一个逻辑为空的顺序表
    //如果new失败，则会抛出一个bad_alloc异常
    ArrayList()noexcept(false);

    //拷贝构造函数，构造一个逻辑上与参数内容相同的顺序表
    //如果new失败，则会抛出一个bad_alloc异常
    ArrayList(const ArrayList &rhs)noexcept(false);

    //原生数组构造函数，构造一个内容与给定数组相同的顺序表
    //如果参数n不大于零，则会抛出一个invalid_argument异常
    //如果new失败，则会抛出一个bad_alloc异常
    ArrayList(int const a[], int n)noexcept(false);

    //填充构造函数，构造一个内容为n个value的顺序表
    //如果参数n不大于零，则会抛出一个invalid_argument异常
    //如果new失败，则会抛出一个bad_alloc异常
    ArrayList(int n, int value)noexcept(false);

    //析构函数，一定要自行实现，否则有内存泄漏
    //通常而言，析构函数不抛出异常
    //如果析构函数中有操作可能会产生异常，则应该在析构函数中就将其catch
    ~ArrayList()noexcept;

    //无话可说
    int getSize() const noexcept { return size; }

    //设置新的容量，同时保证原数据不变！！！
    //如果new失败，则会抛出一个bad_alloc异常
    void setCapacity(int newCapa)noexcept(false);

    //增删查改
    void insert(int pos, int value)noexcept(false);

    void remove(int pos)noexcept(false);

    int at(int pos) const noexcept(false);

    void modify(int pos, int newValue)noexcept(false);

    void disp() const noexcept;
};

#endif // _ARRAYLIST_H_


#include <cstdio>

inline int min(int x, int y) {
    return (x < y) ? x : y;
}

ArrayList::ArrayList() noexcept(false) {
    this->data = nullptr;
    this->size = this->capacity = 0;
}

ArrayList::ArrayList(const ArrayList &rhs)noexcept(false) {
    this->data = new int[rhs.getSize()];
    this->capacity = this->size = rhs.getSize();
    for (int i = 0; i < this->size; ++i) this->data[i] = rhs.at(i);
}

ArrayList::ArrayList(const int *a, int n) noexcept(false) {
    if (n < 0)throw invalid_argument(__func__);
    this->capacity = this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value)noexcept(false) {
    if (n < 0)throw invalid_argument(__func__);
    this->capacity = this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = value;
    }
}

ArrayList::~ArrayList() {
    delete[]this->data;
}

void ArrayList::setCapacity(int newCapa)noexcept(false) {
    int *data = new int[newCapa];
    for (int i = 0; i < min(newCapa, this->size); ++i) {
        data[i] = this->data[i];
    }
    delete[]this->data;
    this->data = data;
    this->size = this->capacity = newCapa;
}

void ArrayList::insert(int pos, int value) noexcept(false) {
    if (pos < 0)throw invalid_argument(__func__);
    this->setCapacity(this->size + 1);
    for (int i = this->size - 1; i > pos; --i)
        this->data[i] = this->data[i - 1];
    this->data[pos] = value;
}

void ArrayList::remove(int pos) noexcept(false) {
    if (pos < 0)throw invalid_argument(__func__);
    for (int i = pos; i < this->size - 1; ++i)
        this->data[i] = this->data[i + 1];
    this->size--;
}

int ArrayList::at(int pos) const noexcept(false) {
    if (pos < 0)throw invalid_argument(__func__);
    return this->data[pos];
}

void ArrayList::modify(int pos, int newValue) noexcept(false) {
    if (pos < 0)throw invalid_argument(__func__);
    this->data[pos] = newValue;
}

void ArrayList::disp() const noexcept {
    for (int i = 0; i < this->size; ++i)
        printf("%d ", this->data[i]);
    printf("\n");
}
