/*
给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`
*/

/*
每次栈顶的元素小于 i墙 的时候
	如果栈里面有2个
		弹出一个栈顶
		求这个凹槽的体积累加
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i ++ )
        {
        	//找到每个柱子左边的第一个高或者相等的柱子、右边的第一个大于的柱子，然后比较两边高度再计算横向凹槽的体积
            while (!stk.empty() && height[stk.top()] < height[i])
            {
                int t = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int len = i - stk.top() - 1;
                int h = min(height[stk.top()], height[i]) - height[t];
                res += h * len;
            }
            stk.push(i);
        }
        return res;
    }
};