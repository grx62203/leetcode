/*
请实现一个函数，把字符串中的每个空格替换成"%20"。

数据范围
0≤ 输入字符串的长度 ≤1000。
注意输出字符串的长度可能大于 1000。
*/
/*
这个题在C++里比较好做，我们可以从前往后枚举原字符串：
	如果遇到空格，则在string类型的答案中添加 "%20"；
	如果遇到其他字符，则直接将它添加在答案中；
但在C语言中，我们没有string这种好用的模板，需要自己malloc出char数组来存储答案。
此时我们就需要分成三步来做：
	遍历一遍原字符串，计算出答案的最终长度；
	malloc出该长度的char数组；
	再遍历一遍原字符串，计算出最终的答案数组；
时间: O(n)
*/
class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for (auto x : str)
            if (x == ' ')
                res += "%20";
            else
                res += x;
        return res;
    }
};