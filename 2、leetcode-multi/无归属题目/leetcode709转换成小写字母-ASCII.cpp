/*
给你一个字符串 `s` ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
*/

class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch: s) {
            if (ch >= 65 && ch <= 90) {
                ch |= 32;//替代与 3232 的加法运算
            }
        }
        return s;
    }
};