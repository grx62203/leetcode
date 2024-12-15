/*
输入一个整数 n，求从 1 到 n 这 n 个整数的十进制表示中 1 出现的次数。

例如输入 12，从 1 到 12 这些整数中包含 “1” 的数字有 1，10，11 和 12，其中 “1” 一共出现了 5 次。

数据范围
1≤n≤109
样例
输入： 12
输出： 5
*/
// time O(logn), really tricky, count bit by bit
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        if (n < 1) return 0;
        int count = 0, factor = 1;
        //从低位遍历到高位
        while (n / factor != 0) {
            int cur_bit = (n / factor) % 10;
            //当前位左边的 数 998188之 1 之 998
            int left = n / (factor * 10);
            //当前位右边的 数 998188之 1 之 88
            int right = n % factor;

            if (cur_bit == 0) {
                count += left * factor;
            }
            else if (cur_bit == 1) {
                count += left * factor + right + 1;
            }
            else {
                count += (left + 1) * factor;
            }
            //998188之 1 之 100
            factor *= 10;
        }
        return count;
    }
};
