/*
输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

保证树中结点值均不小于 0。

数据范围
树中结点的数量 [0,1000]。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> findPath(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, sum, path);
        return ans;
    }

    void dfs(TreeNode *root, int sum, vector<int> &path)
    {
        if (!root) return;
        path.push_back(root->val);//加入路径
        sum -= root->val;         //累加和

        if (!root->left && !root->right && !sum) ans.push_back(path);
        dfs(root->left, sum, path);
        dfs(root->right, sum, path);

        path.pop_back();//恢复现场
        sum += root->val;//恢复现场
    }
};
