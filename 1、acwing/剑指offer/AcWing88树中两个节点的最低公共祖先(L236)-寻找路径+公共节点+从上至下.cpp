/*
给出一个二叉树，输入两个树节点，求它们的最低公共祖先。

一个树节点的祖先节点包括它本身。

注意：

输入的二叉树不为空；
输入的两个节点一定不为空，且是二叉树中的节点；
数据范围
树中节点数量 [0,500]。

样例
二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]如下图所示：
    8
   / \
  12  2
     / \
    6   4

1. 如果输入的树节点为2和12，则输出的最低公共祖先为树节点8。

2. 如果输入的树节点为2和6，则输出的最低公共祖先为树节点2。
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

//分别找出根节点到两个节点的路径，则最后一个公共节点就是最低公共祖先了。
class Solution {
public:
    int findPath(TreeNode*root, TreeNode* p, vector<TreeNode*>&path){
        if(!root)
            return 0;
        if(root->val==p->val){
            path.push_back(root);
            return 1;
        }
        int l = findPath(root->left,p,path);
        int r = findPath(root->right,p,path);
        if(l==1||r==1)
            path.push_back(root);
        return l==1||r==1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        findPath(root,p,path1);
        findPath(root,q,path2);
        if(path1.empty()||path2.empty())  return NULL;
        //从根节点开始，寻找最后一个公共节点
        TreeNode* res =NULL;
        for(int i = 0;i<path1.size();i++){
            if(i>=path1.size()||i>=path2.size())
                break;
            if(path1[path1.size()-1-i]==path2[path2.size()-1-i])
                res = path1[path1.size()-1-i];
            else
                break;
        }
        return res;
    }
};
