/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
 //中序遍历
 //左子树 => 根节点 => 右子树的顺序
 //1、没有左子树，直接遍历该点、然后走到右儿子
 //2、有左子树，先找中序遍历中的前驱节点
 //   p->right = null , 则  p->right = root, root = root->left，说明从上面下来的，然后去左子树遍历
 //   否则，说明从下面上来的，p->right = null，然后遍历当前点，然后遍历右节点， root = root->right;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            //如果当前节点有左儿子，找到左儿子的右后代，是中序遍历过程中当前节点的前一个
            //如果左儿子结束了，从左儿子树的左后一个right可以跳转到当前节点
            //p的操作一直是对每一个没有右儿子的节点的操作，标记中序遍历的下一个
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止，可能是左儿子可能是左子树的最右后代
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，标记当前节点的左子树结束后跳转到当前节点，然后从上到下进入左子树遍历
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要处理当前节点，然后断开链接，然后跳到右孩子或者当前节点的中序遍历下一个
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;       //此时已经经历过p到下一个节点的跳转，所有就可以清空了（上面的某个节点）
                    root = root->right;                 //此刻跳转可能是右子树，可能是中序遍历的下一个（上面的某个节点）
                }
            }
            // 如果没有左孩子，则直接访问根节点、其次跳到右孩子或者当前节点的中序遍历下一个（上面的某个节点）
            else {
                res.push_back(root->val);
                root = root->right;                     //此时跳转的可能是右子树，可能是中序遍历的下一个（上面的某个节点）
            }
        }
        return res;
    }
};