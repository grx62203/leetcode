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
//leetcode
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        int n = s.size();
        //将只出现一次的字符哈希为 索引
        for (int i = 0; i < n; ++i) {
            if (position.count(s[i])) {
                position[s[i]] = -1;
            }
            else {
                position[s[i]] = i;
            }
        }
        int first = n;
        //遍历哈希，排除出现多次的，找到存储的最小的索引
        for (auto [_, pos]: position) {
            if (pos != -1 && pos < first) {
                first = pos;
            }
        }
        return first == n ? ' ' : s[first];
    }
};
