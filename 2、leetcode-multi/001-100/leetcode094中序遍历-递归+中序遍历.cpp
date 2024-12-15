/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
 //中序遍历
 //左子树 => 根节点 => 右子树的顺序
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        //第一次push_back的时候是第一个没有左儿子的左节点
        	//再dfs这个左节点的右儿子子树
        //处理完这个第一个没有左儿子的左节点后，返回处理这个左节点的父亲
        //然后立马去dfs这个父亲的右儿子
        ans.push_back(root->val);
        dfs(root->right);
    }
};
