/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。

要求不能创建任何新的结点，只能调整树中结点指针的指向。

注意：

需要返回双向链表最左侧的节点。
例如，输入下图中左边的二叉搜索树，则输出右边的排序双向链表。
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
    TreeNode* convert(TreeNode* root) {
        if (!root) return NULL;
        auto sides = dfs(root);
        return sides.first;
    }
    //寻找当前节点的最左与最右子节点
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root)
    {
    	//如果没用子节点，返回本身对
        if (!root->left && !root->right) return {root, root};
        //如果当前节点的左儿子和右儿子都在
        if (root->left && root->right)
        {
        	//返回左儿子的左后代，返回右儿子的右后代
            auto lside = dfs(root->left), rside = dfs(root->right);
            //左儿子的右后代是当前节点的前一个节点（中序遍历）
            //右儿子的左后代是当前节点的后一个节点（中序遍历）
            //按照中序遍历的思路将其前后绑定
            lside.second->right = root, root->left = lside.second;
            root->right = rside.first, rside.first->left = root;
            return {lside.first, rside.second};
        }
        //只有左儿子
        if (root->left)
        {
            auto lside = dfs(root->left);
            lside.second->right = root, root->left = lside.second;
            return {lside.first, root};
        }
        //只有右儿子
        if (root->right)
        {
            auto rside = dfs(root->right);
            rside.first->left = root, root->right = rside.first;
            return {root, rside.second};
        }
    }
};