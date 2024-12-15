/*
给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`
*/


//左右同时开始，每次移动左右柱子中小的那个
	//移动边界柱子的时候，计算移动后柱子与当前方向的max柱子差，作为移动后柱子对应的纵向凹槽
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int l = 0, r = height.size() - 1;
        int l_max = height[l], r_max = height[r];
        int res = 0;
        while (l < r - 1)
        {
            if (height[l] < height[r])
            {
                l ++ ;
                int w = l_max - height[l];
                if (w > 0) res += w;
                l_max = max(l_max, height[l]);
            }
            else
            {
                r -- ;
                int w = r_max - height[r];
                if (w > 0) res += w;
                r_max = max(r_max, height[r]);
            }
        }
        return res;
    }
};


class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;

        int res=0;
        int l=0,r=n-1;
        int lMax=height[0],rMax=height[n-1];            //记录l,r遍历过的最大值

        while(l<=r){
            if(lMax<rMax){                              //若lMax小，则i号柱子的积水由lMax决定
                res+=max(0,lMax-height[l]);             //柱子i上方的积水面积累积进res
                lMax=max(lMax,height[l]);               //更新lMax后，指针后移
                l++;
            }else{
                res+=max(0,rMax-height[r]);             //若rMax小，则i号柱子的积水由rMax决定
                rMax=max(rMax,height[r]);               
                r--;
            }
        }
        return res;
    }
};