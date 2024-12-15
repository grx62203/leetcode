/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
*/
/*
设定一个dp数组，dp[i]表示在下标i处能够跳跃的最大值。
	对于dp[i]，它等于dp[i-1]跳一格到达i处后剩余的步数，和nums[i]的最大值。因此得出状态转移方程为：dp[i]=max(dp[i-1]-1,nums[i])
	边界条件：dp[0]=nums[0]
	在每次循环开始，我们判断dp[i-1]是否等于0，若是，则不可能到达下标i处，因此直接返回false。循环结束后 返回true
因为转移状态数组dp只和前一位有关，因此可以用滚动数组简化空间复杂度
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int a=nums[0];  // a=dp[i-1]
        for(int i=1;i<n;i++){
            if(a==0)  return false; // 当没走完的时候，就走不动道了，失败
            a=max(--a,nums[i]);     // a=dp[i]，表示当前位置能向前走的最大距离
        }
        return true;
    }
};

