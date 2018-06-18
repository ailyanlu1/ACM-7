/*
 * Copyright(C): GPL 3.0
 * Author: bitwater
 * Data: 18-6-18
 */


class Solution {
public:
    list<int> lst;

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left)dfs(root->left);
        lst.push_back(root->val);
        if (root->right)dfs(root->right);
    }

    bool isValidBST(TreeNode *root) {
        lst.clear();
        dfs(root);
        int isfirst = 0;
        int last = 0;
        for (auto i:lst) {
            if (isfirst == 0)isfirst = 1;
            else if (last >= i)return false;
            last = i;
        }
        return true;
    }
};

static int _____ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();