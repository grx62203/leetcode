/*给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        queue <TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            //按照加入队列的顺序比较节点值
            if (node1->val != node2->val)                  return false;        
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            //异或---相同为假，不同为真---------有一方的左节点为空，返回假
            if ((left1 == nullptr) ^ (left2 == nullptr))    return false;
            //异或---相同为假，不同为真---------有一方的右节点为空，返回假
            if ((right1 == nullptr) ^ (right2 == nullptr))  return false;
            //先左节点后右节点，两个树加入队列的规则顺序一样
            if (left1 != nullptr)            queue1.push(left1);
            if (right1 != nullptr)           queue1.push(right1);    
            if (left2 != nullptr)            queue2.push(left2);      
            if (right2 != nullptr)           queue2.push(right2);     
        }
        return queue1.empty() && queue2.empty();//同时为空，返回真
    }
};