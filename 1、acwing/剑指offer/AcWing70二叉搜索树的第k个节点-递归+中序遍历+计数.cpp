/*
给定一棵二叉搜索树，请找出其中的第 k 小的结点。

你可以假设树和 k 都存在，并且 1≤k≤ 树的总结点数。

数据范围
树中节点数量 [1,500]。

样例
输入：root = [2, 1, 3, null, null, null, null] ，k = 3

    2
   / \
  1   3

输出：3
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

    TreeNode *ans;

    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    void dfs(TreeNode *root, int &k)
    {
    	//提前返回，剪纸优化
        if (!k || !root) return;
        dfs(root->left, k);
        //操作在左右中间，就是中序遍历
        --k;
        if (!k) ans = root;
        else dfs(root->right, k);
    }
};





// 中序遍历，看清 第k大还是第k小，第k大是 右中左，第k小是 左中右
class Solution {
public:
    int ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    // 这里需要保证所有dfs函数共用一个k，加引用之后 k就相当于全局变量了
    void dfs(TreeNode* root, int& k){ // dfs函数返回值为void, 参数k要加引用&
        if (!root) return; // 搜索到叶子结点就返回
        dfs(root->right, k);           // 右
        if (--k == 0) ans = root->val;   // 中, 也可写成 k--; if (!(k)) ans = root->val;
        if (k > 0) dfs(root->left, k); // 左 加 if (k > 0) 可以剪枝优化
    }
};
// 方法一：dfs(TreeNode* root, int& k)中把k作为参数传入 同时加上引用&，相当于全局变量
// 中序遍历，看清 第k大还是第k小，第k大是 右中左，第k小是 左中右
class Solution {
public:
    int ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    // 这里需要保证所有dfs函数共用一个k，加引用之后 k就相当于全局变量了
    void dfs(TreeNode* root, int& k){ // dfs函数返回值为void, 参数k要加引用&
        if (!root) return; // 搜索到叶子结点就返回
        dfs(root->right, k);           // 右
        if (k == 0) return;   // 利用k值进行剪枝
        if (--k == 0){                // 中
            ans = root->val;
            return;           // 剪枝
        }
        dfs(root->left, k);            // 左
    }
};
// 方法二：把k作为全局变量，就不用dfs递归的时候把k做参数传入同时加引用&，更好理解
class Solution {
public:
    int k, ans; //注意这里直接把 k 转变为全局变量，否则就要 在dfs(TreeNode* root, int& k)中把k作为参数传入 同时加上引用&
    int kthLargest(TreeNode* root, int _k) {
        k = _k;  // k 转化为全局变量
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root){
        if (!root) return; // 搜索到叶子结点就返回
        dfs(root->right);             // 右
        if (k == 0) return;   // 利用k值进行剪枝
        if (--k == 0){                // 中
            ans = root->val;
            return;           // 剪枝
        }
        dfs(root->left);             // 左
    }
};
