/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */



const int SIZE = 10000 + 500;
const double eps = 1e-7;
int fa[SIZE];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

struct _t {
    int lastId, newId;
    int pos;
    double needT;
};

int cmp1(const _t &a, const _t &b) {
    return a.pos > b.pos;
}

int cmp2(const _t &a, const _t &b) {
    if (abs(a.needT - b.needT) < eps)return a.lastId > b.lastId;
    return a.needT < b.needT;
}

_t peo[SIZE];


class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        for (int i = 0; i < position.size(); ++i) {
            fa[i] = i;
            peo[i].pos = position[i];
            peo[i].needT = (double) (target - position[i]) / speed[i];
        }
        ssize_t n = position.size();
        sort(peo, peo + n, cmp1);
        for (int i = 0; i < n; ++i)peo[i].lastId = i;
        sort(peo, peo + n, cmp2);
        for (int i = 0; i < n; ++i)peo[i].newId = i;
        sort(peo, peo + n, cmp1);
        int p = 0, pid = 0;
        for (int i = 0; i < n; ++i) {
            if (peo[i].newId >= p)p = peo[i].newId, pid = i;
            else unite(i, pid);
        }
        set<int> st;
        for (int i = 0; i < n; ++i)st.insert(find(i));
        return st.size();
    }
};