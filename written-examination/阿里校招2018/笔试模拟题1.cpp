//
// Created by bitwater on 18-5-7.
//

#include<bits/stdc++.h>

using namespace std;

/*!< 未知数据大小与分布 */
vector<int> vt;
map<int, int> mp;

int main(int argc, char *argv[]) {
    int n, k;
    while (cin >> n >> k) {
        mp.clear();
        vt.clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % k == 0 && x)continue;
            if (mp.count(x % k) == 0)
                mp[x % k] = 1;
            else
                mp[x % k]++;
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int j = k - i;
            if (mp.count(i) == 0)continue;
            if (i == j) {
                ans++;
                continue;
            }
            if (mp.count(j) == 0)ans += mp[i];

            else if (mp[i] > mp[j] || (mp[i] == mp[j] && i < j))
                ans += mp[i];
        }
        cout << ans << endl;
    }
}