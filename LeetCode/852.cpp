/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-17
 */


class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i + 1] < A[i])return i;
    }
};

