/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。
*/

/*
结果ans的长度最长为a和b长度最大值加一。
把a和b和结果ans三个数字最低位对齐。
某一位的值为 int val = ai ^ bj ^ carry;
这位产生的进位 carry = (ai & bj) | (carry & (ai ^ bj));
当其中一个数，比如b不够时，在高位补0。
然后去掉结果ans高位多余的0。
*/

class Solution {
public:
    string addBinary(const string& a, const string& b) {
        string ans(1+max(a.size(), b.size()), '0');
        int carry = 0;
        for (int i=a.size()-1, j=b.size()-1, k=ans.size()-1; 0<=k; --i,--j,--k) {
            const int ai = 0 <= i ? a[i] - '0' : 0;
            const int bj = 0 <= j ? b[j] - '0' : 0;
            const int val = ai ^ bj ^ carry;
            carry = (ai & bj) | (carry & (ai ^ bj));
            ans[k] = val + '0';
        }
        const int p = ans.find_first_not_of('0');
        return p == string::npos ? "0" : ans.substr(p);
    }
};