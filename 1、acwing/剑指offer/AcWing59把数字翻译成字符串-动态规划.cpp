/*
给定一个数字，我们按照如下规则把它翻译为字符串：

0 翻译成 a，1 翻译成 b，……，11 翻译成 l，……，25 翻译成 z。

一个数字可能有多个翻译。

例如 12258 有 5 种不同的翻译，它们分别是 bccfi、bwfi、bczi、mcfi 和 mzi。

请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

数据范围
输入数字位数 [1,101]。

样例
输入："12258"

输出：5
*/
class Solution {
public:
    int getTranslationCount(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        //f[0]的值需要保证边界是对的，即f[1]和f[2]是对的
        //在任何情况下f[0]取1都可以保证f[1]和f[2]是正确的，所以f[0]应该取1
        f[0] = 1;
        //对应s[0]~s[n-1]
        for (int i = 1; i <= n; i ++ )
        {
            f[i] = f[i - 1];
            int t = (i >= 2) * (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (t >= 10 && t <= 25) f[i] += f[i - 2];
        }
        return f[n];
    }
};

//倒推
class Solution {
public:
    int getTranslationCount(string s) {
        int n = s.size();
        if(!n) return 0;
        if(n==1) return 1;

        vector<int> dp(n+1, 0);
        //对应s[n-1]
        dp[n-1] = 1;
        //对应s[in-2]~s[0]
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i+1];
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'6')){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};

//leetcode,0是非法的
class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        //q表示i时候的总数量，i一个算
        //p表示i-1时候的总数量，i-1、i合起来算
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q; //i-1对应的数量，=i-1一位数转化方法数=i-1、i两位数转化数量
            q = r; //i对应的数量，=i一位数转化方法数
            r = 0;
            //1、默认当前位一位数转化
            r += q;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            //2、如果可以两位转化，则累加当前数两位数转化
            if (pre <= "25" && pre >= "10") {
                r += p;
            }
        }
        return r;
    }
};