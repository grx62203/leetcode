/*
给定一个正整数 `n` ，你可以做如下操作：

1. 如果 `n` 是偶数，则用 `n / 2`替换 `n` 。
2. 如果 `n` 是奇数，则可以用 `n + 1`或`n - 1`替换 `n` 。

`n` 变为 `1` 所需的最小替换次数是多少？
*/
class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                ++ans;
                n /= 2;
            }
            else if (n % 4 == 1) {
                ans += 2;
                n /= 2;
            }
            else {
                //这是最大的特例，等于3的时候，选择 -1 再除以2
                if (n == 3) {
                    ans += 2;
                    n = 1;
                }
                else {
                    ans += 2;
                    n = n / 2 + 1;
                }
            }
        }
        return ans;
    }
};