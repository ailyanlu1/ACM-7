//
// Created by bitwater on 18-5-10.
//

/*!<
 * 水题 把一个0-99999 的数字转换为中文大写, 万用W 千用Q ...
 *
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int get_len(int x) {
    int ret = 1;
    while (x > 9)x /= 10, ret++;
    return ret;
}

inline int get_pos(int x, int pos) {
    switch (pos) {
        case 1:
            return x % 10;
        case 2:
            return x % 100 / 10;
        case 3:
            return x % 1000 / 100;
        case 4:
            return x % 10000 / 1000;
        case 5:
            return x % 100000 / 10000;
        default:
            exit(1);
    }

}

inline char ptr(int pos) {
    switch (pos) {
        case -1:
            return 'L';
        case 0:
            return '-';
        case 1:
            return 'S';
        case 2:
            return 'B';
        case 3:
            return 'Q';
        case 4:
            return 'W';
        default:
            exit(1);
    }
}

int main(int argc, char *argv[]) {
    int x;
    char str[10];
    while (cin >> x) {
        int len = get_len(x);
//        cout << get_len(x) << endl;
        if( x == 0){
            printf("L\n");
            continue;
        }
        for (int i = 0; i < len; ++i) {
            int p = get_pos(x, len - i);
            if (p) {
                printf("%d", p);
                if (len - i - 1)
                    printf("%c", ptr(len - i - 1));
            } else {
                int j = i;
                while (j < len && get_pos(x, len - (j)) == 0)j++;
                i = j - 1;
                if (i != len - 1)
                    printf("%c", ptr(-1));
            }
        }
        printf("\n");
    }
    return 0;
}