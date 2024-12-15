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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        while (root || stk.size()) {
            //走到没有左节点为止
            while (root) {
                stk.push(root);
                root = root->left;
            }
            //先操作第一个没有左儿子的左节点---直到这个没有左儿子的左节点的所在子树都处理完，才上返
                //如果这个左节点有右儿子，先处理这个右儿子一家（依旧是先操作这个右儿子的左儿子，再这个右儿子本身，最后这个右儿子的右儿子）
                //如果这个左节点没有右儿子，就弹出处理这个左节点的父亲
                    //如果这个左节点的父亲有右儿子，那么再处理这个右儿子一家（依旧是先操作这个右儿子的左儿子，再这个右儿子本身，最后这个右儿子的右儿子）
            root = stk.top();
            stk.pop();
            res.push_back(root->val);

            root = root->right;
        }

        return res;
    }
};
