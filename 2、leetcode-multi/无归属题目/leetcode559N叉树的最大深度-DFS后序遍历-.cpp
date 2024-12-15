/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 0;
        for (auto c: root->children) res = max(res, maxDepth(c));
        return res + 1;
    }
};