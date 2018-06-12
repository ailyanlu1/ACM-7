/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-12
 */


class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans;
        for (int i = 0; i < num1.size(); ++i)
            for (int j = 0; j < num2.size(); ++j) {
                while (i + j >= ans.size())ans.push_back(0);
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        size_t idx = 0, mid = ans.size() - 1;
        while (idx < mid || ans[idx] > 9) {
            if (idx >= mid)ans.push_back(0);
            ans[idx + 1] += ans[idx] / 10;
            ans[idx] = ans[idx] % 10;
            idx++;
        }
        string ret;
        ssize_t st = ans.size() - 1;
        while (ans[st] == 0)st--;
        for (ssize_t i = 0; i <= st; ++i)ret.push_back(ans[i] + '0');
        if (ret.size() == 0)ret.push_back('0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};