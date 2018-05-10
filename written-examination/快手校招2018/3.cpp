//
// Created by bitwater on 18-5-10.
//

/*!<
 *
 * 模拟题 wa了
 * 鬼知道那里错了,
 * 给n个矩形
 * (x,y) 表示 矩形边长为 2^x, 有y个这样的盒子
 * (x+1, ? ) 可以嵌套4个(x,?) 的盒子
 * (x+2, ? ) 可以嵌套4*4个(x,?) 的盒子
 * 问 用一个 盒子嵌套所有的盒子, 最小的半径是多少
 * */

#include<bits/stdc++.h>

using namespace std;

struct _t {
    int x, y;

    _t(int xx = 0, int yy = 0) : x(xx), y(yy) {}

    friend bool operator<(const _t &a, const _t &b) {
        return a.x < b.x;
    }
};

const int SIZE = 100000 + 300;
_t box[SIZE];

int get_pix(int x, int j, int &le) {
    le = x % (1 << (j << 1));
    return x / (1 << (j << 1));
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        memset(box,0, sizeof(box));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &box[i].x, &box[i].y);
        sort(box, box + n);
        box[n].x = box[n - 1].x + 1;
        box[n].y = 0;
        for (int i = 0; i < n; ++i) {
            int le;
            int p = get_pix(box[i].y, box[i + 1].x - box[i].x, le);
//            cout << p << " " << le << endl;
            if (le) p++;
            box[i + 1].y = max(p, box[i + 1].y);
        }
        int j = n;
        while (1) {
            if (box[j].y == 1)break;
            box[j + 1].x = box[j].x + 1;
            box[j + 1].y = 0;
            int le;
            int p = get_pix(box[j].y, box[j + 1].x - box[j].x, le);
            if (le) p++;
            box[j + 1].y = max(p, box[j + 1].y);
            j++;
        }
        printf("%d\n", box[j].x);
    }
    return 0;
}