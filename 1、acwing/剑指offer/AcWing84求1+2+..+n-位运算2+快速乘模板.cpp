/*
求 1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 (A?B:C)。

数据范围
1≤n≤1000。

样例
输入：10

输出：55
*/

//求和也就是求 n*(n+1)/2
class Solution {
private:
    int c[2];
    bool mul(int& a, int& b, long long& ans) {
    	//找到b的最低位是1还是0，然后如果是0-ans累加0，如果是1-ans累加与a&的结果
        ans += c[b & 1] & a; 
        //用b的从低位到高位的每一位 乘以 a，这样子得考虑b得那一位的位置
        //b移动是为了遍历b的每一位
        //a移动是为了平衡b的每一位的左移位置量
        b >>= 1, a <<= 1;
        return b && mul(a, b, ans);
    }
public:
    int getSum(int n) {
    	//c[1]=1111111111111111111111111111111
        c[1] = (1ll << 32) - 1;
        int a = 1 + n; long long ans = 0;
        mul(a, n, ans);
        return ans >> 1;
    }
};
