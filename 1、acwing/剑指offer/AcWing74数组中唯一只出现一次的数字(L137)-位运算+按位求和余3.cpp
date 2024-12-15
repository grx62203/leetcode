/*
在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。

请找出那个只出现一次的数字。

你可以假设满足条件的数字一定存在。

思考题：

如果要求只使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
数据范围
数组长度 [1,1500]。

样例
输入：[1,1,1,2,2,2,3,4,4,4]

输出：3
*/

//看每一位1的数量
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ans = 0;
        //从高位遍历到低位，每一次都需要对答案操作
        for (int i = 31; i >= 0; --i) {
            int cnt = 0;
            for (int x: nums) {
                if (x >> i & 1) {
                    cnt ++;
                }
            }
            //答案的当前位是1
            if (cnt % 3 == 1) {
                ans = (ans * 2) + 1;
            }
            //答案的当前位是0
            else {
                ans = ans * 2;
            }
        }
        return ans;
    }
};

//因为出现三次的数的某位的和一定可以%3=0，如果全部的某位相加%3=1，则答案某位为1
//一共32个位，统计哪个位 1 出现次数 % 3 == 1，那么所求数该位为1，最后合起来就是答案
//答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ans = 0;
        //从低位遍历到高位，至于位为1的时候需要对答案操作
        for (int i = 0; i < 32; ++ i ) {
            int cnt = 0;
            for (auto x : nums) {
                if (x >> i & 1) cnt ++; 
                //cnt += ((num >> i) & 1);
            }
            //将答案的当前位是置于1
            if (cnt % 3) {
                ans |= 1 << i;
            }
            //答案当前位为0不需要操作
        }

        return ans;
    }
};
