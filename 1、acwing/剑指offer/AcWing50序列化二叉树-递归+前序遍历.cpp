/*
请实现两个函数，分别用来序列化和反序列化二叉树。

您需要确保二叉树可以序列化为字符串，并且可以将此字符串反序列化为原始树结构。

数据范围
树中节点数量 [0,1000]。

样例
你可以序列化如下的二叉树
    8
   / \
  12  2
     / \
    6   4

为："[8, 12, 2, null, null, 6, 4, null, null, null, null]"
以上的格式是AcWing序列化二叉树的方式，你不必一定按照此格式，所以可以设计出一些新的构造方式。
8 12 2 null null 6 4 null null null null
以上是字符串的形式，有一个空格
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    void dfs_s(TreeNode *root, string &res)
    {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string data, int &u)
    {
        if (u == data.size()) return NULL;
        int k = u;
        //k记录当前数字的位数如134是个三位数的数字，56是个两位数的数字，退出的时候，k指向了字符的中间的空格，所以回到下个字符的首部需要加1.
        while (data[k] != ' ') k ++ ;？
        //碰到了null，u指向下一个元素的第一个位置（中间空格后一个），且返回
        if (data[u] == 'n') {        
            u = k + 1;
            return NULL;
        }
        int val = 0, sign = 1;
        //如果是负数，u指向当前元素的符号位之后的位置，此时u指向正字符元素第一个位置，k指向元素最后一个位置后一个
        if (u < k && data[u] == '-') sign = -1, u ++ ;
        //将这一个元素从前到后取出来赋值
        for (int i = u; i < k; i ++ ) val = val * 10 + data[i] - '0';
        //乘以符号位
        val *= sign;
        //u指向下一个元素的第一个位置
        u = k + 1;
        //前序遍历的顺序
        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);
        return root;
    }
};