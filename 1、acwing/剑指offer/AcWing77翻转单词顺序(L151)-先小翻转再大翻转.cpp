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

//需要新开一个数组，如果案例有空数组
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i ++ )
        {
            int j = i;
            while (j < s.size() && s[j] != ' ') j ++ ;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
