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
    ArrayList();

    //拷贝构造函数，构造一个逻辑上与参数内容相同的顺序表
    ArrayList(const ArrayList &rhs);

    //原生数组构造函数，构造一个内容与给定数组相同的顺序表
    ArrayList(int const a[], int n);

    //填充构造函数，构造一个内容为n个value的顺序表
    ArrayList(int n, int value);

    //析构函数，一定要自行实现，否则有内存泄漏
    ~ArrayList();

    //无话可说
    int getSize() const { return size; }

    //设置新的容量，同时保证原数据不变！！！
    void setCapacity(int newCapa);

    //增删查改
    void insert(int pos, int value);

    void remove(int pos);

    int at(int pos) const;

    void modify(int pos, int newValue);

    void disp() const;

    //赋值运算符重载
    ArrayList &operator=(const ArrayList &rhs);

    ArrayList &operator+=(const ArrayList &rhs);

    //方括号运算符重载
    int &operator[](int pos);

    const int &operator[](int pos) const;
};

#endif // _ARRAYLIST_H_

#include <cstdio>
#include <algorithm>

using namespace std;


ArrayList::ArrayList() {
    this->data = nullptr;
    this->size = this->capacity = 0;
}

ArrayList::ArrayList(const ArrayList &rhs) {
    this->data = new int[rhs.getSize()];
    this->capacity = this->size = rhs.getSize();
    for (int i = 0; i < this->size; ++i) this->data[i] = rhs.at(i);
}

ArrayList::ArrayList(const int *a, int n) {
    this->capacity = this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value) {
    this->capacity = this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = value;
    }
}

ArrayList::~ArrayList() {
    delete[]this->data;
}

void ArrayList::setCapacity(int newCapa) {
    int *data = new int[newCapa];
    for (int i = 0; i < min(newCapa, this->size); ++i) {
        data[i] = this->data[i];
    }
    delete[]this->data;
    this->data = data;
    this->size = min(newCapa, this->size);
    this->capacity = newCapa;
}

void ArrayList::insert(int pos, int value) {
    if (this->size == this->capacity)
        this->setCapacity(this->size + 1);

    for (int i = this->size; i > pos; --i)
        this->data[i] = this->data[i - 1];
    this->size++;
    this->data[pos] = value;
}

void ArrayList::remove(int pos) {
    for (int i = pos; i < this->size - 1; ++i)
        this->data[i] = this->data[i + 1];
    this->size--;
}

int ArrayList::at(int pos) const {
    return this->data[pos];
}

void ArrayList::modify(int pos, int newValue) {
    this->data[pos] = newValue;
}

void ArrayList::disp() const {
    for (int i = 0; i < this->size; ++i)
        printf("%d ", this->data[i]);
    printf("\n");
}

ArrayList &ArrayList::operator=(const ArrayList &rhs) {
    printf("=\n");
    if (this->data != nullptr)delete[]this->data;
    this->size = rhs.getSize();
    this->data = new int[this->size];
    this->capacity = this->size;
    for (int i = 0; i < this->size; ++i)
        this->data[i] = rhs.at(i);
//    disp();
    return *this;
}

ArrayList &ArrayList::operator+=(const ArrayList &rhs) {
//    disp();
//    rhs.disp();
    printf("+=\n");
    for (int i = 0; i < rhs.getSize(); ++i) {
        this->insert(this->getSize(), rhs.at(i));
    }
//    disp()
    //printf("size %d\n", this->size);
    return *this;
}

int &ArrayList::operator[](int pos) {
    return this->data[pos];
}

const int &ArrayList::operator[](int pos) const {
    return this->data[pos];
}
