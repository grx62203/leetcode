/*
给你 `n` 个非负整数 `a1，a2，...，a``n`，每个数代表坐标中的一个点 `(i, ai)` 。在坐标内画 `n` 条垂直线，垂直线 `i` 的两个端点分别为 `(i, ai)` 和 `(i, 0)` 。找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

**说明：**你不能倾斜容器。
- `n == height.length`
- `2 <= n <= 105`
- `0 <= height[i] <= 104`
*/

//证明很严谨。 其实无论是移动短指针和长指针都是一种可行求解。 只是，一开始就已经把指针定义在两端，如果短指针不动，而把长指针向着另一端移动，两者的距离已经变小了，无论会不会遇到更高的指针，结果都只是以短的指针来进行计算。 故移动长指针是无意义的。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
            //移动矮的一边
        }
        return res;
    }
};
