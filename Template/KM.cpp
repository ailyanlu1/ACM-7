/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */


#include <stdio.h>
#include <string.h>

#define M 310
#define inf 0x3f3f3f3f

int n, nx, ny;
int lx[M], ly[M];    //lx,ly为顶标，nx,ny分别为x点集y点集的个数
int _visx[M], _visy[M], w[M][M], _slack[M], _link[M];

int DFS(int x) {
    _visx[x] = 1;
    for (int y = 1; y <= ny; y++) {
        if (_visy[y])
            continue;
        int t = lx[x] + ly[y] - w[x][y];
        if (t == 0)       //
        {
            _visy[y] = 1;
            if (_link[y] == -1 || DFS(_link[y])) {
                _link[y] = x;
                return 1;
            }
        } else if (_slack[y] > t)  //不在相等子图中_slack 取最小的
            _slack[y] = t;
    }
    return 0;
}

int KM() {
    int i, j;
    memset(_link, -1, sizeof(_link));
    memset(ly, 0, sizeof(ly));
    for (i = 1; i <= nx; i++)            //lx初始化为与它关联边中最大的
        for (j = 1, lx[i] = -inf; j <= ny; j++)
            if (w[i][j] > lx[i])
                lx[i] = w[i][j];

    for (int x = 1; x <= nx; x++) {
        for (i = 1; i <= ny; i++)
            _slack[i] = inf;
        while (1) {
            memset(_visx, 0, sizeof(_visx));
            memset(_visy, 0, sizeof(_visy));
            if (DFS(x))     //若成功（找到了增广轨），则该点增广完成，进入下一个点的增广
                break;  //若失败（没有找到增广轨），则需要改变一些点的标号，使得图中可行边的数量增加。
            //方法为：将所有在增广轨中（就是在增广过程中遍历到）的X方点的标号全部减去一个常数d，
            //所有在增广轨中的Y方点的标号全部加上一个常数d
            int d = inf;
            for (i = 1; i <= ny; i++)
                if (!_visy[i] && d > _slack[i])
                    d = _slack[i];
            for (i = 1; i <= nx; i++)
                if (_visx[i])
                    lx[i] -= d;
            for (i = 1; i <= ny; i++)  //修改顶标后，要把所有不在交错树中的Y顶点的_slack值都减去d
                if (_visy[i])
                    ly[i] += d;
                else
                    _slack[i] -= d;
        }
    }
    int res = 0;
    for (i = 1; i <= ny; i++)
        if (_link[i] > -1)
            res += w[_link[i]][i];
    return res;
}

int main() {
    int i, j;
    while (scanf("%d", &n) != EOF) {
        nx = ny = n;
        //  memset (w,0,sizeof(w));
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                scanf("%d", &w[i][j]);
        int ans = KM();
        printf("%d\n", ans);
    }
    return 0;
}
