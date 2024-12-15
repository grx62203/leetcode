/*
从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。

数据范围
树中节点的数量 [0,1000]。
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
将根节点插入队列中；
创建一个新队列，用来按顺序保存下一层的所有子节点；
对于当前队列中的所有节点，按顺序依次将儿子加入新队列，并将当前节点的值记录在答案中；
重复步骤2-3，直到队列为空为止。

时间：n
*/
class Solution {
public:
    vector<int> get_val(vector<TreeNode*> level)
    {
        vector<int> res;
        for (auto &u : level)
            res.push_back(u->val);
        return res;
    }

    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>>res;
        if (!root) return res;
        vector<TreeNode*>level;
        level.push_back(root);
        res.push_back(get_val(level));
        while (true)
        {
            vector<TreeNode*> newLevel;
            for (auto &u : level)
            {
                if (u->left) newLevel.push_back(u->left);
                if (u->right) newLevel.push_back(u->right);
            }
            if (newLevel.size())
            {
                res.push_back(get_val(newLevel));
                level = newLevel;
            }
            else break;
        }
        return res;
    }
};





/*
在上一道题 《不分行从上往下打印二叉树》 的基础上修改代码。

区别在于，每一层结束的时候，往queue里塞一个NULL做标记。

在queue里读取一个数出来之后，先看看是不是level标识符NULL(因为是BFS，当前level读完，
下一个level有哪些要读的也都放在queue里了，可以在queue结尾给加一个新的NULL), 是的话再看看是不是整个树读完了(即queue里没有点了)。

时间复杂度分析：每个点遍历一次
*/
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); //root层的标识符

        vector<int> cur;
        while(q.size()){
            TreeNode* t = q.front();
            q.pop();

            if(t){ //跟上一道题同样的操作
                cur.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else{
                if(q.size()) q.push(NULL); 
                res.push_back(cur); 
                cur.clear();
            }
        }
        return res;

    }
};
