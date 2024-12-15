/*给定一棵二叉树的其中一个节点，请找出中序遍历序列的下一个节点。

注意：
如果给定的节点是中序遍历序列的最后一个，则返回空节点;
二叉树一定不为空，且给定的节点一定不是空节点；
数据范围
树中节点数量 [0,100]。
*/
/*
分情况讨论即可，如下图所示：
	如果当前节点有右儿子，则右子树中最左侧的节点就是当前节点的后继。比如F的后继是H；
	如果当前节点没有右儿子，则需要沿着father域一直向上找，找到第一个是其father左儿子的节点，该节点的father就是当前节点的后继。
比如当前节点是D，则第一个满足是其father左儿子的节点是F，则C的father就是D的后继，即F是D的后继。
时间：O（h）
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
    	//1、找右子树的最左节点
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }
        //2、找当前节点的父亲及父父亲，如果遍历的某个父是右子节点，就停止，这就是目标
        while (p->father && p == p->father->right) p = p->father;
        return p->father;
    }
};

