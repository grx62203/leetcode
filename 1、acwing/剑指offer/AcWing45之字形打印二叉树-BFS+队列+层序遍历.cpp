/*
请实现一个函数按照之字形顺序从上向下打印二叉树。

即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
	对于当前队列中的所有节点，按顺序依次将儿子插入新队列；
	按从左到右、从右到左的顺序交替保存队列中节点的值；
	重复步骤2-4，直到队列为空为止。
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
        bool zigzag = true;
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
                vector<int>temp = get_val(newLevel);
                if (zigzag)
                    reverse(temp.begin(), temp.end());
                res.push_back(temp);
                level = newLevel;
            }
            else break;
            zigzag = !zigzag;
        }
        return res;
    }
};





class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root); int i = 1;
        while(q.size())
        {
            int len = q.size();
            vector<int> lev;
            for(int j = 0; j < len; j++)    //队列长度，为该层的节点个数
            {
                auto t = q.front();
                q.pop();
                lev.push_back(t->val);
                // if(i % 2 == 0)    //  偶数行,右到左打印，他的下一层先放左边 这样有错误！！
                // {
                //     if(t->left) q.push(t->left);
                //     if(t->right) q.push(t->right);
                // }
                // else
                // {
                //     if(t->right) q.push(t->right);
                //     if(t->left) q.push(t->left);                    
                // }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);                      
            }
            if(i % 2 == 0) reverse(lev.begin(),lev.end());    //偶数行直接数组倒排就是了！！！
            res.push_back(lev);  i++;
        }
        return res;
    }
};
