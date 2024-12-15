/*
输入一棵二叉树的根结点，判断该树是不是平衡二叉树。

如果某二叉树中任意结点的左右子树的深度相差不超过 1，那么它就是一棵平衡二叉树。

注意：

规定空树也是一棵平衡二叉树。
数据范围
树中节点数量 [0,500]。

样例
输入：二叉树[5,7,11,null,null,12,9,null,null,null,null]如下所示，
    5
   / \
  7  11
    /  \
   12   9

输出：true
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
//从下到上的递归，类似于后序遍历，每个节点遍历一次
class Solution {
public:

    bool ans = true;

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    //返回的时当前节点到他的最小后代的距离-1，也可以理解为当前节点的最高高度
    //没有儿子的节点的最高高度为1
    int dfs(TreeNode *root)
    {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        //当左右儿子的最高高度差 大于1，代表两者的最小后代的高度差大于1，也就不满足平衡二叉树了
        //也代表叶子节点深度差大于1了
        if (abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
};


//从上到下的递归，每个节点遍历两次
class Solution {
public:
    int height(TreeNode* root)      //计算二叉树深度的模板，背就完了
    {
        if (!root) return 0;
        else return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        else return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
