/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。

请定义一个函数实现字符串左旋转操作的功能。

比如输入字符串"abcdefg"和数字 2，该函数将返回左旋转 2 位得到的结果"cdefgab"。

注意：

数据保证 n 小于等于输入字符串的长度。
数据范围
输入字符串长度 [0,1000]。

样例
输入："abcdefg" , n=2

输出："cdefgab"
*/

/*
substr有2种用法：
假设：string s = "0123456789";

string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"

string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"
*/
class Solution {
public:
    string leftRotateString(string str, int n) {

        return str.substr(n)+str.substr(0,n);
    }
};


//leetcode
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tempstr1(s, 0, n);
        string tempstr2(s, n);
        return tempstr2 + tempstr1;
    }
};