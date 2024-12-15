/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {NULL};
        vector<TreeNode*> res;
        //遍历 左右子树的数量分割，总和为r-l+1
        for (int i = l; i <= r; i ++ ) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto l: left)
                for (auto r: right) {
                    //root当前一个子集
                    auto root = new TreeNode(i);
                    //左边 链接 left中所有的可能的树，右边 链接 right中所有可能的树
                    root->left = l, root->right = r;
                    res.push_back(root);
                }
        }
        //返回l-r的所有匹配方案（可以作为更大范围的一个子树，也是答案的一个子集序列）
        return res;
    }
};