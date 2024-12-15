/*
请实现一个函数，把字符串中的每个空格替换成"%20"。

数据范围
0≤ 输入字符串的长度 ≤1000。
注意输出字符串的长度可能大于 1000。
*/
/*
扩大str长度，每一次都是用前面的填充后面的，不会冲突
时间:原字符串只会被遍历常数次，所以总时间复杂度是 O(n)
*/
class Solution {
public:
    string replaceSpaces(string &str) {

        int len = 0;
        for (auto c : str)
            if (c == ' ')
                len += 3;
            else
                len ++ ;

        int i = str.size() - 1, j = len - 1;

        str.resize(len);

        while (i >= 0)
        {
            if (str[i] == ' ')
            {
                str[j -- ] = '0';
                str[j -- ] = '2';
                str[j -- ] = '%';
            }
            else str[j -- ] = str[i];
            i -- ;
        }
        return str;
    }
};
