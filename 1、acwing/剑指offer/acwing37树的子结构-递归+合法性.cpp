/*
输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。

我们规定空树不是任何树的子结构。

数据范围
每棵树的节点数量 [0,1000]。
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
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        if (isSame(pRoot1, pRoot2)) return true;
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }

    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return true;
        if (!pRoot1 || pRoot1->val != pRoot2->val) return false;
        return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }
};



class Solution {
public:
    bool hasSubtree(TreeNode* a, TreeNode* b) {
        if(!a||!b)return false;
        return helper(a,b)||hasSubtree(a->left,b)||hasSubtree(a->right,b);
    }
    // 判断b是否是以a为根节点的子结构
    bool helper(TreeNode* a,TreeNode* b){
        if(!b)return true;
        if(!a||a->val!=b->val)return false;
        return helper(a->left,b->left)&&helper(a->right,b->right);
    }
};
