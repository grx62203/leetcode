/*
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
*/
//f 是求 (n−i−1)!，表示按第 i 位分组之后，每一组中排列的个数。
//从第 n−1 位到第 i 位都确定以后，还剩下 n−i−1 个数，所以每组的排列个数就是 (n−i−1)!
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> st(10);
        //从前到后枚举每一位
        for (int i = 0; i < n; i ++ ) {
            int fact = 1;
            for (int j = 1; j <= n - i - 1; j ++ ) fact *= j;
            //在当前位上，从小到大枚举每个数
            	//如果当前数字对应的后面可能性比 k 小，被减去
            	//如果当前数字对应的后面可能性 比 k 大， 说明 k 就是其中一种可能
            //没一位，都会找到一个数字 j， 被添加sting
            for (int j = 1; j <= n; j ++ ) {
                if (!st[j]) {
                    if (fact < k) k -= fact;
                    else {
                        res += to_string(j);
                        st[j] = true;
                        break;
                    }
                }
            }
        }

        return res;
    }
};
