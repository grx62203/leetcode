/*
给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
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
 /*
寻找相邻逆序对
    第一次碰到逆序对，记录前a，后b
    第二次碰到逆序对，记录后c
    如果一次，交换 ab
    如果两次，交换 ac
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->val < pred->val) {
                //更新两次逆序对后半部分
                y = root;
                //更新一次逆序对前半部分
                if (x == nullptr) {
                    x = pred;
                }
                else break;
            }
            pred = root;       //按照中序遍历来说，pred一直存储的是下一次遍历的节点的中序前一个
            root = root->right;
        }

        swap(x->val, y->val);  //交换节点的值
    }
};
