/*
 * @Date     : 2018/07/01
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
 */


class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int cnt_5(0), cnt_10(0);
        for (auto i:bills) {
            if (i == 5)
                cnt_5++;
            if (i == 10) {
                if (cnt_5)cnt_5--, cnt_10++;
                else return false;
            }
            if (i == 20) {
                if (cnt_10 && cnt_5)cnt_10--, cnt_5--;
                else if (cnt_5 >= 3)cnt_5 -= 3;
                else return false;
            }
        }
        return true;
    }
};