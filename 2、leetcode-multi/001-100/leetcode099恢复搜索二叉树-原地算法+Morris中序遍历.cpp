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
 1、没有左子树，直接遍历该点、然后走到右儿子
 2、有左子树，先找中序遍历中的前驱节点
    p->right = null , 则  p->right = root, root = root->left，说明从上面下来的，然后去左子树遍历
    否则，说明从下面上来的，p->right = null，然后遍历当前点，然后遍历右节点， root = root->right;
3、寻找相邻逆序对
    第一次碰到逆序对，记录前a，后b
    第二次碰到逆序对，记录后c
    如果一次，交换 ab
    如果两次，交换 ac
 */
//24ms
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second, *last = NULL;
        while (root) {
            if (!root->left) {
                //找到逆序对，last是前面的，root是当前节点
                if (last && last->val > root->val) {
                    //第一次找到
                    if (!first) first = last, second = root;
                    //第二次找到，只需要更新后一个节点
                    else second = root;
                }
                //记录前一个节点，按照中序遍历顺序跳转下一个
                last = root;
                root = root->right;
            } else {
                auto p = root->left;
                //找到 root 在中序遍历的前驱节点
                while (p->right && p->right != root) p = p->right;
                //如果从上面下来的，先遍历左子树
                if (!p->right) p->right = root, root = root->left;
                //如果从下面上来的，清空p的右孩子，然后遍历当前节点，再遍历右节点
                else {
                    p->right = NULL;
                    //找到逆序对，last是前面的，root是当前节点
                    if (last && last->val > root->val) {
                        //第一次找到
                        if (!first) first = last, second = root;
                        //第二次找到，只需要更新后一个节点
                        else second = root;
                    }
                    //记录前一个节点，按照中序遍历顺序跳转下一个
                    last = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};