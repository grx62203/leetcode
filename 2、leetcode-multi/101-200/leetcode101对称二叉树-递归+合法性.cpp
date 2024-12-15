/*给你一个二叉树的根节点 root ， 检查它是否轴对称。*/

/*[1,2,2,2,null,2]是二叉树的层序遍历，画出来之后可以发现，左右不对称，但是左根右和右根左的遍历结果是相同的。*/

/*
递归判断两个子树是否互为镜像。

两个子树互为镜像当且仅当：

两个子树的根节点值相等；
第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像；
时间复杂度分析：从上到下每个节点仅被遍历一遍，所以时间复杂度是 O(n)O(n)。
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
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root->left, root->right);
    }

    bool dfs(TreeNode*p, TreeNode*q)
    {
        if (!p || !q) return !p && !q;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};
