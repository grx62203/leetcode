/*
将一个骰子投掷 n 次，获得的总点数为 s，s 的可能范围为 n∼6n。

掷出某一点数，可能有多种掷法，例如投掷 2 次，掷出 3 点，共有 [1,2],[2,1] 两种掷法。

请求出投掷 n 次，掷出 n∼6n 点分别有多少种掷法。

数据范围
1≤n≤10
样例1
输入：n=1

输出：[1, 1, 1, 1, 1, 1]

解释：投掷1次，可能出现的点数为1-6，共计6种。每种点数都只有1种掷法。所以输出[1, 1, 1, 1, 1, 1]。
样例2
输入：n=2

输出：[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]

解释：投掷2次，可能出现的点数为2-12，共计11种。每种点数可能掷法数目分别为1,2,3,4,5,6,5,4,3,2,1。

      所以输出[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]。
*/



//优化滚动数组
class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int>dp(6*n+1, 0);
        for(int i = 1;i<=6;i++)  dp[i] = 1;
       	//正序遍历每一个骰子
        for(int i = 2;i<=n;i++)
        	//倒序遍历每一种可能性，因为滚动数组会被循环利用，如果正序，求f[7]的时候调用的f[6]已经被修改
        	//当然倒序依旧利用的 旧f[]、与这一个 j组合循环内的其他已知未知数据无关
            for(int j = 6*i;j>=0;j--){
            	//滚动数组清空,得到的最后一个dp[j]对应的是i=n的结果
                dp[j] = 0;
                for(int k = 6;k>=1;k--){
                	if (j >= k)  dp[j] += dp[j-k];
                }
            }
        vector<int>res(dp.begin()+n, dp.end());
        return res;
    }
};



//
class Solution {
public:
    vector<double> twoSum(int n) {
        //dp
        vector<int> f(6*n+1,0);
        f[0] = 1;//f[0][0]=1
        for(int i=1;i<=n;i++)
            for(int j=6*i;j>=i;j--){//倒着推导 但是不同于背包问题 不存在不选的情况 所以不能直接用f[j]+=f[j-k]
                int tmp = 0;
                for(int k=1;k<=min(6,j-i+1);k++) tmp += f[j-k];
                //f[j] += f[j-k];//f[i][j] += f[i-1][j-k] k=1,2,3,4,5,6 这样直接处理会统计上k==0 错误 不完全与背包相同
                f[j] = tmp;
            }
        vector<double> res(5*n+1);//n - 6n
        double sum = 0;
        for(int i=n;i<=6*n;i++) sum += f[i];
        for(int i=n;i<=6*n;i++) res[i-n] = f[i]/sum;
        return res;
    }
};