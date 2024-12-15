/*
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。

输入一个数组，求出这个数组中的逆序对的总数。

数据范围
给定数组的长度 [0,100]。

样例
输入：[1,2,3,4,5,6,0]

输出：6
*/
/*

*/
//leetcode
//树状数组https://leetcode.cn/problems/count-of-smaller-numbers-after-self/solution/shu-zhuang-shu-zu-by-liweiwei1419/
/*
1、lowbit有关，求最小位的1，0010的结果是0010，0110的结果是0010
2、最低位的1后面没有0的节点C都没有儿子了，
3、每一个节点C加上它的lowbit就是它的父亲，也就是单点更新的路线
4、树状数组C的每一个节点都代表一部分原数组A的一部分的和
5、C[0110]=A[0110]+C[0100]
*/
class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }
    //前缀和，减去lowbit，不是找儿子
    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }
    //单点更新，加上lowbit，就是找父亲
    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        // 离散化，将数转化为非连续索引（返回指向大于等于key的第一个值的位置）
        sort(tmp.begin(), tmp.end());
        for (int& num: nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        // 树状数组统计逆序对，此时的树状树里面，出现一次，+1
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
        	//求前缀和，意思就是字面意义上的A数组的前缀和,不过只需要累加C数组，C数组是多叉树
        	//求0110的前缀和，就是C[0110]+C[0100]=A[6]+A[5]+A[4]+A[3]+A[2]+A[1]
        	//===从后遍历标记累加出现的每个数，前缀和也就是求后面有几个比当前数小的数，即逆序对
        	ans += bit.query(nums[i] - 1);
            //单点A[0010]更新，只更当前C[0010]、父亲C[00]、父亲的父亲C等等，这样子累加前缀和只需要累加C
            bit.update(nums[i]);
        }
        return ans;
    }
};
