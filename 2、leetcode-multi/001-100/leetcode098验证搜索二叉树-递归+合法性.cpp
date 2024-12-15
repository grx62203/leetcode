/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs(root)[0];
    }

    vector<int> dfs(TreeNode* root) {
        //假设 合法  ，而且到了最底层的话本身值是min  本身值是max
        vector<int> res({1, root->val, root->val});
        if (root->left) {
            //返回左子树的情况
            auto t = dfs(root->left);
            //如果左子树非法 或者 左子树的最大值大于节点值 ---非法
            if (!t[0] || t[2] >= root->val) res[0] = 0;
            //更新节点与左子树 集合 的min、max
            res[1] = min(res[1], t[1]);
            res[2] = max(res[2], t[2]);//左子树不更新max也能ac
        }
        if (root->right) {
            auto t = dfs(root->right);
            if (!t[0] || t[1] <= root->val) res[0] = 0;
            res[1] = min(res[1], t[1]);//右子树不更新min也能ac
            res[2] = max(res[2], t[2]);
        }
        //返回树的 标志是否合法  最小值  最大值
        //如果没有子节点，就返回 合法 本身值 本身值
        return res;
    }
};


class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr)                                 return true;
        if (root -> val <= lower || root -> val >= upper)    return false;
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};