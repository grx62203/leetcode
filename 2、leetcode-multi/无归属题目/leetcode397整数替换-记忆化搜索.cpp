/*
给定一个正整数 `n` ，你可以做如下操作：

1. 如果 `n` 是偶数，则用 `n / 2`替换 `n` 。
2. 如果 `n` 是奇数，则可以用 `n + 1`或`n - 1`替换 `n` 。

`n` 变为 `1` 所需的最小替换次数是多少？
*/
class Solution {
private:
    unordered_map<int, int> memo;

public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        if (n % 2 == 0) {
            return memo[n] = 1 + integerReplacement(n / 2);
        }
        return memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};
