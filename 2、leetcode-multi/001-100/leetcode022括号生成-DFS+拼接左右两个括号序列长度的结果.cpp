/*
数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

有效括号组合需满足：左括号必须以正确的顺序闭合。

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/


/*
我们需要枚举与第一个 ‘(’ 对应的 ‘)’ 的位置 2i + 1
递归调用 generate(i) 即可计算 a 的所有可能性；
递归调用generate(n−i−1) 即可计算 b 的所有可能性；
遍历 a 与 b 的所有可能性并拼接，即可得到所有长度为 2n 的括号序列。

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr)   return cache[n];
        if (n == 0)    cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                    	//固定一种规则，left与right的范围从0开始
                        result -> push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }
        return cache[n];
    }
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};