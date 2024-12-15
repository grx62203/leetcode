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
/*
就在中序递归遍历的基础上改了一点点，用一个pre指针保存中序遍历的前一个结点。
因为是中序遍历，遍历顺序就是双线链表的建立顺序；
每一个结点访问时它的左子树肯定被访问过了，所以放心大胆的改它的left指针，不怕树断掉；
同理，pre指向的结点保存的数肯定小于当前结点，所以其左右子树肯定都访问过了，所以其right指针也可以直接改。

最后需要一直向左找到双向链表的头结点。
*/
class Solution {
public:

    TreeNode* pre = NULL;

    TreeNode* convert(TreeNode* root) {
        dfs(root);
        while(root && root->left) root = root->left;

        // leetcode 是 循环链表,  要加上 这里
        // 循环链表 首尾相连, pre 最后在 链表尾结点
        //head->left = pre, pre->right = head;

        return root;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);

        root->left = pre;
        if(pre) pre->right = root;
        pre = root;

        dfs(root->right);
    }
};
