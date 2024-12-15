/*
输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。

我们规定空树不是任何树的子结构。

数据范围
每棵树的节点数量 [0,1000]。
*/
/*
一层迭代
	首先需要迭代遍历树中所有节点，这里可以采用至少四种方法。前序遍历，后序遍历，栈实现的中序遍历，Morris中序遍历等等。我这里提供栈实现的前序遍历。
二层迭代
	这个过程封装在compare方法中，我的思路时使用队列，就像层序遍历那样添加子节点。不过需要注意的是，我们为了判断B是A的子结构，需要让A队列按照B的结构添加子节点

	对于B中有的节点，A中却没有对应位置的节点，则说明A不能包含B
	对于A中的有的节点，而B的没有的，我们选择对这种情况忽略。
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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        Deque<TreeNode> deque = new LinkedList<>();
        if (B == null) return false;
        if (A == null) return false;
        deque.push(A);
        while (!deque.isEmpty()) {
            TreeNode node = deque.pop();
            if (dfs(node, B)) return true;
            if (node.right != null) deque.push(node.right);
            if (node.left != null) deque.push(node.left);
        }
        return false;
    }

    private boolean dfs(TreeNode a, TreeNode b) {
        //保证根节点相同的情况下，判断b是否是a的子结构
        if (a.val != b.val) return false;
        Deque<TreeNode> deque1 = new LinkedList<>();
        Deque<TreeNode> deque2 = new LinkedList<>();
        deque1.offer(a);
        deque2.offer(b);
        while (!deque2.isEmpty()) {
            TreeNode node1 = deque1.poll();
            TreeNode node2 = deque2.poll();
            if (node1.val != node2.val) return false;
            if (node2.left != null) {
                //按照B的树结构走，也要判断A中有没有呀 如果B有的A没有，那么就不匹配 如果A有的B没有，ok的
                //
                if (node1.left == null) return false;
                deque1.offer(node1.left);
                deque2.offer(node2.left);
            }
            if (node2.right != null) {
                //
                if (node1.right == null) return false;
                deque1.offer(node1.right);
                deque2.offer(node2.right);
            }
        }
        return true;
    }

};