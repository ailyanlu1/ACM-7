/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-5-29
 */
#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

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
};

#endif // _ARRAYLIST_H_


ArrayList::ArrayList() {
    this->size = 0;
    this->data = nullptr;
}

ArrayList::ArrayList(const ArrayList &rhs) {
    this->size = rhs.getSize();
    this->data = new int[this->size];

}

ArrayList::ArrayList(const int *a, int n) {
    this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value) {
    this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = value;
    }
}

ArrayList::~ArrayList() {
    delete[]this->data;
}
