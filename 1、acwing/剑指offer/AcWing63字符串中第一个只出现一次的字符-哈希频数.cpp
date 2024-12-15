/*
在字符串中找出第一个只出现一次的字符。

如输入"abaccdeff"，则输出b。

如果字符串中不存在只出现一次的字符，返回 # 字符。

数据范围
输入字符串长度 [0,1000]。

样例：
输入："abaccdeff"

输出：'b'
*/
class Solution {
public:
    char firstNotRepeatingChar(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c] ++ ;
        char res = '#';
        for (auto c : s)
            if (hash[c] == 1)
            {
                res = c;
                break;
            }
        return res;
    }
};
