/*
 * @Date     : 2018/07/01
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
 */


map<int, int> v;
map<int, int> ls;
map<int, int> rs;
map<int, int> father;

void dfs1(TreeNode *root) {

    if (root->left) {
        ls[root->val] = root->left->val;
        father[root->left->val] = root->val;
        dfs1(root->left);
    }
    if (root->right) {
        rs[root->val] = root->right->val;
        father[root->right->val] = root->val;
        dfs1(root->right);
    }
}

map<int, int> dep;

vector<int> ans;
int k;

void dfs2(int tar, int last) {
    if (dep[tar] == k)ans.push_back(tar);
    if (father.count(tar) && father[tar] != last) {
        dep[father[tar]] = dep[tar] + 1;
        dfs2(father[tar], tar);
    }
    if (ls.count(tar) && ls[tar] != last) {
        dep[ls[tar]] = dep[tar] + 1;
        dfs2(ls[tar], tar);
    }
    if (rs.count(tar) && rs[tar] != last) {
        dep[rs[tar]] = dep[tar] + 1;
        dfs2(rs[tar], tar);
    }

}

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        father.clear();
        ls.clear();
        rs.clear();
        dep.clear();
        dfs1(root);
        k = K;
        ans.clear();
        dfs2(target->val, -1);
        //for (auto i :ans)cout << i << " ";cout << endl;
        return ans;
    }
};
