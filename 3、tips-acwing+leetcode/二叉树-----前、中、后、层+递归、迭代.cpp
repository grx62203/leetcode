https://blog.csdn.net/qq583083658/article/details/88960893?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-88960893-blog-115415401.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-88960893-blog-115415401.pc_relevant_default&utm_relevant_index=1

1 迭代法
迭代法比递归法稍微复杂一点，但无非就是借助栈或队列来实现二叉树的遍历

1.1 前序遍历（Leetcode 144）
前序遍历: 当栈不为空或者root不为空节点时，先遍历、访问、压栈左节点，当左节点不存在时，出栈访问右节点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        // 当栈不为空或者root不为空节点时
        while(!s.empty() || temp){
        //`先遍历、访问、压栈左节点`
            while(temp){
                s.push(temp);
                res.push_back(temp->val);
                temp = temp->left;
            }
        //当访问节点不存在左子树时，退栈对右子树进行访问
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
        return res;
    }
};


1.2 中序遍历（Leetcode 94）
与前序遍历类似，当栈不为空或者root不为空节点时，先遍历、压栈左节点，当左节点不存在时，出栈先访问栈顶节点，然后访问右节点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        //当栈不为空或则根节点不为空节点时
        while(!s.empty() || temp){
            //先`遍历、压栈左节点`
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            //当`左节点不存在时`，出栈`先访问栈顶节点`，`然后访问右节点`
            temp = s.top();
            s.pop();
            res.push_back(temp->val);
            temp = temp->right;
        }
        return res;
    }
};

1.3 后序遍历（Leetcode 145）
与前序遍历类似，只不过前序遍历先遍历、访问、压栈左节点，当左节点不存在时，出栈访问右节点
而后序遍历当栈不为空或者root不为空节点时，先遍历、访问、压栈右节点，当右节点不存在时，出栈访问左节点，最后**翻转数组**


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //与前序遍历类似，只不过前序遍历先遍历、访问、压栈左节点，当左节点不存在时，出栈访问右节点
    //后序遍历先遍历、访问、压栈右节点，当右节点不存在时，出栈访问左节点，最后翻转数组
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while(!s.empty() || tmp){
            //先遍历、访问、压栈右节点
            while(tmp){
                res.push_back(tmp->val);
                s.push(tmp);
                tmp = tmp->right;
            }
            //当右节点不存在时，出栈访问左节点
            tmp = s.top();
            s.pop();
            tmp = tmp->left;
        }
        //最后翻转数组
        reverse(res.begin(), res.end());
        return res;
    }
};


1.4 层序遍历（Leetcode 102）
使用队列，按每一层从左到右的节点出现顺序来存储节点
求出每一层队列的长度，每访问队列的一个头节点，就把该节点出列
并判断是否该节点有左子节点或右子节点，如果有，则加入到队列尾，为访问下一层做准备


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        // 使用队列，按每一层从左到右的节点出现顺序来存储节点
        queue<TreeNode*> q;
        q.push(root);
        // 当队列不为空时
        while(!q.empty()){
            // 求出每一层队列的长度，
            int qLen = q.size();
            vector<int> tmp;
            for(int i=0; i<qLen; ++i){
                // 每访问队列的一个头节点，就把该节点出列
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                 // 并判断是否该节点有左子节点或右子节点，如果有，则加入到队列尾，为访问下一层做准备
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};



2 递归法
代码比较简短，思路逻辑也很清晰。就是建立一个辅助函数，以实现递归。

2.1 前序遍历（Leetcode 144）

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res){
        if(root){
            res.push_back(root->val);
           helper(root->left, res);
           helper(root->right, res);
        } 
        else return ;

    }
};


2.2 中序遍历（Leetcode 94）

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

     void helper(TreeNode* root, vector<int> &res){
        if(root){
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        } 
        else return ;
    }
};


2.3 后序遍历（Leetcode 145）

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> res;
         helper(root, res);
         return res;
    }
    void helper(TreeNode* root, vector<int> &res){
        if(root){
            helper(root->left, res);
            helper(root->right, res);
            res.push_back(root->val);
        } 
        else return ;
    }
};


2.4 层序遍历（Leetcode 102）
要点有几个：

利用depth变量记录当前在第几层（从0开始），进入下层时depth + 1；
如果depth >= vector.size()说明这一层还没来过，这是第一次来，所以得扩容咯；
因为是前序遍历，中-左-右，对于每一层来说，左边的肯定比右边先被遍历到，实际上前序和中序结果都是一样的。



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode *root, int depth, vector<vector<int>> &ans){
        if (!root) return ;
        if (depth >= ans.size())
            ans.push_back(vector<int> {});
        ans[depth].push_back(root->val);
        helper(root->left, depth + 1, ans);
        helper(root->right, depth + 1, ans);
    }
};
