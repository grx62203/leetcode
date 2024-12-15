/*
输入一个英文句子，单词之间用一个空格隔开，且句首和句尾没有多余空格。

翻转句子中单词的顺序，但单词内字符的顺序不变。

为简单起见，标点符号和普通字母一样处理。

例如输入字符串"I am a student."，则输出"student. a am I"。

数据范围
输入字符串长度 [0,1000]。

样例
输入："I am a student."

输出："student. a am I"
*/

//满足leetcode那一道题
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        // 逆序双指针
        for (int i = s.size() - 1; i >= 0; i -- ) {
            if (s[i] != ' ') {
                int r = i;
                while (i >= 0 && s[i] != ' ') i -- ;
                ans += s.substr(i + 1, r - i) + " ";
            }
        }
        //去掉最后一个空格
        return ans.substr(0, ans.size() - 1);
    }
};
