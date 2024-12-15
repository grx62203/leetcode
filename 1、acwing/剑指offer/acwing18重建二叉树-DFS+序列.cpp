/*
输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。

注意:
二叉树中每个节点的值都互不相同；
输入的前序遍历和中序遍历一定合法；
数据范围
树中节点数量范围 [0,100]。
*/
/*
递归建立整棵二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。

具体步骤如下：
	先利用前序遍历找根节点：前序遍历的第一个数，就是根节点的值；
	在中序遍历中找到根节点的位置 k，则 k 左边是左子树的中序遍历，右边是右子树的中序遍历；
	假设左子树的中序遍历的长度是 l，则在前序遍历中，根节点后面的 l 个数，是左子树的前序遍历，剩下的数是右子树的前序遍历；
	有了左右子树的前序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；
时间：O（n）
空间：O（n）
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

    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;//存储中序遍历的值与对应位置
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return NULL;
        int k = pos[pre[pl]] - il;             //中序遍历的分界点，如果是根节点的话，前面是当前位置的左子树，后面是当前位置的右子树，每一次都是找到当前树的根节点
        TreeNode* root = new TreeNode(pre[pl]);//前序遍历的第一个就是根节点，先建立根节点，再分开求左子树和右子树，再递归向下求左节点为根节点与右节点为根节点的结果
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);//dfs就是明确根节点的位置，把前序遍历和中序遍历都分为两部分分别dfs，然后每次dfs都是一个根节点为主的重建
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
};

//wwb
class Solution {
public:
    int a[110];
    int b[110];
    
    TreeNode* calc(int l1, int r1, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2)  return NULL;
        
        int k = 0;
        for (int i = l2; i <= r2; i ++)
        {
            if (b[i] == a[l1])
            {
                k = i;
                break;
            }
        }
        
        TreeNode *Node = new TreeNode(0);
        Node -> val = a[l1];
        
        int num = k - l2;
        
        Node -> left = calc(l1 + 1, l1 + num, l2, l2 + num - 1);
        Node -> right = calc(l1 + num + 1, r1, l2 + num + 1, r2);
        
        return Node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        
        for (int i = 0; i < n; i ++)
        {
            a[i + 1] = preorder[i];
            b[i + 1] = inorder[i];
        }
        
        TreeNode *node = new TreeNode(0);
        
        node = calc(1, n, 1, m);
        
        return node;
    }
};