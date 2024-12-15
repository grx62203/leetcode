/*
输入一个整数 n，求从 1 到 n 这 n 个整数的十进制表示中 1 出现的次数。

例如输入 12，从 1 到 12 这些整数中包含 “1” 的数字有 1，10，11 和 12，其中 “1” 一共出现了 5 次。

数据范围
1≤n≤109
样例
输入： 12
输出： 5
*/
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        if (!n) return 0;
        vector<int> number;
        //存储从低位到高位的每一位数字
        while (n) number.push_back(n % 10), n /= 10;
        long long res = 0;
        //从高位遍历到低位
        for (int i = number.size() - 1; i >= 0; i -- )
        {
            int left = 0, right = 0, t = 1;
            //求得i位左边的数（998188遍历到1时，left=998）
            for (int j = number.size() - 1; j > i; j -- ) left = left * 10 + number[j];
            //求得i位左边的数（998188遍历到1时，right=88）求得t=100，代表1后面有2个0的级别
            for (int j = i - 1; j >= 0; j -- ) right = right * 10 + number[j], t *= 10;
           	//998*100
            res += left * t;
        	//此时代表 188部分中百位1出现 88 + 1 = 89次，包括100-188
            if (number[i] == 1) res += right + 1;
            //此时代表 288部分百位1出现 100次，包括100-199全部
            else if (number[i] > 1) res += t;
        }
        return res;
    }
};