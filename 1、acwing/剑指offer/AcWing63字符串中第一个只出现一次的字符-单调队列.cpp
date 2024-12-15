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
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!position.count(s[i])) {
                position[s[i]] = i;
                q.emplace(s[i], i);
            }
            else {
            	//曾经出现过的字符标记
                position[s[i]] = -1;
                //按照顺序弹出曾经出现过的字符
                while (!q.empty() && position[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? ' ' : q.front().first;
    }
};
