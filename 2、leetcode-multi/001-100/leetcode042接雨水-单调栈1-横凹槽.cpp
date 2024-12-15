/*
给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`
*/


//需要判定凹槽一定存在，且滞后计算对应体积（左中右）=栈顶（左）、last（中）、i（右）
	//第一次进循环的时候，公式无效，存下当前柱子高度，弹出当前柱子，
	//后面还能进循环，就代表还存在比i柱子低的，代表可以计算刚才弹出去的柱子所在的凹槽了
	//左中右，右边高，取决于左中高度差，是一个扁矩形
	//res += (height[stk.top()] - last) * (i - stk.top() - 1);
	//如果没进while循环，栈不空，代表没有前面比i柱子还低的只有比i柱子高的，此时公式无效
	//如果退出while循环，栈不空，代表可以计算刚才最后弹出的柱子对应凹槽了
	//左中右，右边高，取决于左中高度差，是一个扁矩形
    //if (stk.size()) res += (i - stk.top() - 1) * (height[i] - last);

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;//存所有的高度
        int res = 0;
        for (int i = 0; i < height.size(); i ++ ) {
            int last = 0;
            while (stk.size() && height[stk.top()] <= height[i]) {      //非空 且 栈顶元素 小于等于 当前高度
				//top是左边即将被弹出的，如果是左边第一个，
				//第一次进循环的时候，公式无效，存下当前柱子高度，弹出当前柱子，
                //后面还能进循环，就代表还存在比i柱子低的，代表可以计算刚才弹出去的柱子所在的凹槽了
				//左中右，右边高，取决于左中高度差，是一个扁矩形
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                //last是左边即将被弹出的高度
                last = height[stk.top()];  
                //将所有比i柱子低的都弹出去                             
                stk.pop(); 
                
            }
		    //如果没进while循环，栈不空，代表没有前面比i柱子还低的只有比i柱子高的，此时公式无效
		    //如果退出while循环，栈不空，代表可以计算刚才最后弹出的柱子对应凹槽了
		    //左中右，右边高，取决于左中高度差，是一个扁矩形
            if (stk.size()) res += (i - stk.top() - 1) * (height[i] - last);
            stk.push(i);
        }

        return res;
    }
};
