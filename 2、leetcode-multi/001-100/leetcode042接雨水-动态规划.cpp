/*
给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`
*/

// 动态规划 (3 次扫描): 时间O(n), 空间O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        if (n == 0)
            return 0;

        vector<int> left_max(n), right_max(n);

        left_max[0] = height[0];
        for (int i = 1; i < n; i++) 
            left_max[i] = max(left_max[i - 1], height[i]);

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], height[i]);

        // i = 0和n-1 肯定无积水, 这里 i的范围可以为[0/1, n-2/n-1]
        for (int i = 0; i < n; i++)
            ans += min(left_max[i], right_max[i]) - height[i];

        return ans;
    }
};


// 动态规划 (2 次扫描): 时间O(n), 空间O(n)
// 上面 lMax[i] 只与 lMax[i - 1]有关, 且 lMax 数组 是从左向右更新
// 所以 计算答案数组时 如果 从左向右遍历时(也可以从右向左遍历), 
// 就可以 将 lMax数组 优化成 一个变量
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        if (!n) return 0; // n == 0 需要特判

        int lMax;
        vector<int> rMax(n);

        // lMax[0] = h[0];
        // for (int i = 1; i < n; i ++) // i-1>=0, i>=1
        //     lMax[i] = max(lMax[i - 1], h[i]);

        rMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i --) // i+1<=n-1, i<=n-2
            rMax[i] = max(rMax[i + 1], h[i]);

        lMax = h[0];
        for (int i = 1; i < n; i ++) { // [0/1, n-2/n-1]
            lMax = max(lMax, h[i]);
            ans += min(lMax, rMax[i]) - h[i];
        }    

        return ans;
    }
};
