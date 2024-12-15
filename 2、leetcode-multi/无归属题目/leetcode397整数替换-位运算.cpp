/*
给定一个正整数 `n` ，你可以做如下操作：

1. 如果 `n` 是偶数，则用 `n / 2`替换 `n` 。
2. 如果 `n` 是奇数，则可以用 `n + 1`或`n - 1`替换 `n` 。

`n` 变为 `1` 所需的最小替换次数是多少？
*/

观察一个数的二进制表示方式，该题相当于消除多余的1，直到最后只剩下最低位一个 1。

对于偶数肯定是只能除以 2 处理
但是，对于奇数有两种情况：
	如果只有最低位一位是 1，我们应该做减 1 处理，
		因为如果减 1 可以直接消除一个 1，
		而加 1 的话，这个 1 会跑到倒数第 2 位，后面做了除以 2 之后还是要处理这个 1，会增加一次操作；
	如果低位有连续的 1，我们应该做加 1 处理，
		因为此时我们做加 1 操作会把连续的 1 全部变成 0，直到不连续的那个 0 变成 1，
		而减 1 的话只能把最低位一个 1 变成 0，显然，加 1 能更减少操作次数；

class Solution {
    public int integerReplacement(int n) {
        long num = n;
        int ans = 0;
        while (num > 1) {
            if ((num & 1) == 0) {
                // 是偶数
                num >>= 1;
            } else if ((num & 0b10) == 0 || num == 3) {
                // 0b表示二进制，跟0x表示十六进制一样的
                // 倒数第二位是0，说明只有最低位是1
                // 3是个特例
                num--;
            } else {
                num++;
            }
            ans++;
        }
        return ans;
    }
}