/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

*/
//152ms

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n);

        //因为每次弹出去的总是比前一个大，所以当后一个更小的时候会把前一个弹出，此时会跳过比前一个更大的那些位置
        //所以这个单调栈会弹出大的，留下小的，单调递增
        stack<int> stk;
        //存储左边第一个比它低的位置
        for (int i = 0; i < n; i ++ ) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        //存储右边第一个比它低的位置
        for (int i = n - 1; i >= 0; i -- ) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            //右边第一个比它低的位置 - 左边第一个比它低的位置 - 1 = 当前位最大矩形
            res = max(res, h[i] * (right[i] - left[i] - 1));
        }

        return res;
    }
};



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        heights.push_back(-1);
        // 为了算法书写方便，在数组末尾添加高度 -1
        // 这会使得栈中所有数字在最后出栈。
        stack<int> st;
        for (int i = 0; i <= n; i++) {
        	//遍历i位的时候，计算的是以栈顶为基准 弹出前面更大的位置，求得栈顶对应的最大矩形
        	//每一个栈顶cur 的右边i是右边第一个更小的
        	//每一个栈顶cur 的左边是cur对应的旧栈顶，也比cur小
        	//单调栈，每次弹出比当前i位更大的，保持单调递增,所以每个栈顶的前一个栈元素，都是左边第一个更小的
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();

                if (st.empty())
                    ans = max(ans, heights[cur] * i);
                else
                    ans = max(ans, heights[cur] * (i - st.top() - 1));
            }
            st.push(i);
        }

        return ans;
    }
};