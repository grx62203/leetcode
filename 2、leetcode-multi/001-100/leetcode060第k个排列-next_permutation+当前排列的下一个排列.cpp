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
/*
1、
#include <algorithm>
bool next_permutation(iterator start,iterator end)
当当前序列不存在下一个排列时，函数返回false，否则返回true
2、
 do
{
    printf("%s\n",ch);
}while(next_permutation(ch,ch+strlen(ch),cmp));
3、
next_permutation（start,end），和prev_permutation（start,end）。
这两个函数作用是一样的，区别就在于前者求的是当前排列的下一个排列，后一个求的是当前排列的上一个排列。
至于这里的“前一个”和“后一个”，我们可以把它理解为序列的字典序的前后，严格来讲，就是对于当前序列pn，他的下一个序列pn+1满足：
	不存在另外的序列pm，使pn<pm<pn+1.
*/
//116ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        for (int i = 1; i <= n; i ++ ) res += to_string(i);
        for (int i = 0; i < k - 1; i ++ ) {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};