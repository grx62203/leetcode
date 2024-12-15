/*
输入一个二叉树，将它变换为它的镜像。

数据范围
树中节点数量 [0,100]。
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
    void mirror(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};