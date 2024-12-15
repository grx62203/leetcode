/*
输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

保证树中结点值均不小于 0。

数据范围
树中结点的数量 [0,1000]。
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
我们也可以采用广度优先搜索的方式，遍历这棵树。当我们遍历到叶子节点，且此时路径和恰为目标和时，我们就找到了一条满足条件的路径。

为了节省空间，我们使用哈希表记录树中的每一个节点的父节点。每次找到一个满足条件的节点，我们就从该节点出发不断向父节点迭代，即可还原出从根节点到当前节点的路径。

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-68dg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
//leetcode
class Solution {
public:
    vector<vector<int>> ret;
    unordered_map<TreeNode*, TreeNode*> parent; //关联子节点和父节点
    /*路径输出函数
     *从左右子树为空的结点开始，循环向上找父节点
     *并且将路过的结点值加入列表中
     */
    void getPath(TreeNode* node){
        vector<int> tmp;
        while(node!=nullptr){   
            tmp.emplace_back(node->val);
            node = parent[node];
        }
        reverse(tmp.begin(),tmp.end()); //因为从子节点向上遍历，所以调转列表顺序
        ret.emplace_back(tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == nullptr) //判空
            return ret;
        queue<TreeNode*> q_node;    //存结点队列
        queue<int> q_sum;   //存路径和队列
        q_node.emplace(root);   //根节点入队
        q_sum.emplace(0);
        while(!q_node.empty()){
            TreeNode* node = q_node.front();
            q_node.pop();
            int rec = q_sum.front() + node->val;    //将广度优先搜索到的结点的值存入rec中
            q_sum.pop();
            /*
             *只有node为叶子结点且这一路结点和等于目标值
             *才运行路径输出函数
             */
            if(node->left == nullptr && node->right == nullptr){
                if(rec == target)
                    getPath(node);
            }
            /*
             *否则左子树不为空
             *将左子树结点加入结点队列
             *此结点为子树几点的父节点
             *此条路径和加入路径队列中
             *右子树同理
             */
            else{
                if(node->left!=nullptr){
                    q_node.emplace(node->left);
                    parent[node->left] = node;
                    q_sum.emplace(rec);
                }
                if(node->right!=nullptr){
                    q_node.emplace(node->right);
                    parent[node->right] = node;
                    q_sum.emplace(rec);
                }
            }
        }
        return ret;
    }
};
