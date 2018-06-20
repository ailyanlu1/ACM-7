/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-18
 */



class Solution {

public:

    double largestTriangleArea(vector <vector<int>> &points) {
        double ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans = max(ans, abs(((double) (points[i][0] * (points[k][1] - points[j][1]) +
                                                  points[k][0] * (points[j][1] - points[i][1]) +
                                                  points[j][0] * (points[i][1] - points[k][1])))) / 2);
        return ans;
    }
};

static int _____ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();