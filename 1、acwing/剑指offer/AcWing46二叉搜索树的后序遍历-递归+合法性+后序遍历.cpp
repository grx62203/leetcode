/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。

如果是则返回true，否则返回false。

假设输入的数组的任意两个数字都互不相同。

数据范围
数组长度 [0,1000]。
*/
//可以将最后一个元素看作根节点，然后将前面分为两部分，这两部分递归下去都可以再分为两部分
//	dfs全部——递归前半部分和后半部分——递归前前半部分、前后半部分、后前半部分、后后半部分——
//	返回合法性
//	如果前半部分都小于根节点、后半部分都大于根节点，则合法
//	如果dfs到底都合法，那么合法	
//因为空树也是一棵二叉搜索树，所以当输入空链表时，我们应该返回true。
//递归时，右子树的坐标范围应该是[k, r - 1]，而不是[k + 1, r]。

class Solution {
public:

    vector<int> seq;

    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;
        if (seq.empty()) return true;
        return dfs(0, seq.size() - 1);
    }

    bool dfs(int l, int r) {
        if (l >= r) return true;
        int root = seq[r];
        int k = l;
        while (k < r && seq[k] < root) k ++ ;
        for (int i = k; i < r; i ++ )
            if (seq[i] < root)
                return false;
        return dfs(l, k - 1) && dfs(k, r - 1);
    }
};
