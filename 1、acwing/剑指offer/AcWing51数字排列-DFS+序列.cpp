/*
输入一组数字（可能包含重复数字），输出其所有的排列方式。

数据范围
输入数组长度 [0,6]。

样例
输入：[1,2,3]

输出：
      [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
      ]
*/

//枚举数字。--------找位置
//也可以枚举位置----找数字
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.resize(nums.size());
        dfs(nums, 0, 0, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int u, int start, int state)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        //如果当前数字和前一个数字重复，则只能选择前一个数字选择位置之后的位置
        //如果                不重复，则可以选择全部位置
        if (!u || nums[u] != nums[u - 1]) start = 0;
        //遍历若干位置
        for (int i = start; i < nums.size(); i ++ )
            //如果当前位置没有被选择。用二进制表示。右移i位，&1，得结果为0表示没有被选择。得结果为1表示被选择了
            if (!(state >> i & 1))
            {
                path[i] = nums[u];
                //默认下一个数字、默认下一个位置（可改）、模型下一个被选择状态（以及把当前选择这个位置标记了）
                dfs(nums, u + 1, i + 1, state + (1 << i));
            }
    }
};


/*
由于有重复元素的存在，这道题的枚举顺序和 Permutations 不同。

    先将所有数从小到大排序，这样相同的数会排在一起；
    从左到右依次枚举每个数，每次将它放在一个空位上；
    对于相同数，我们人为定序，就可以避免重复计算：我们在dfs时记录一个额外的状态，记录上一个相同数存放的位置 startstart，我们在枚举当前数时，只枚举 start+1,start+2,…,nstart+1,start+2,…,n 这些位置。
    不要忘记递归前和回溯时，对状态进行更新。
时间复杂度分析：搜索树中最后一层共 n! 个节点，前面所有层加一块的节点数量相比于最后一层节点数是无穷小量，可以忽略。且最后一层节点记录方案的计算量是O(n)O(n)，所以总时间复杂度是 O(n×n!)O(n×n!)。
*/
class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u, int start)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        //遍历若干位置
        for (int i = start; i < nums.size(); i ++ )
            //如果当前位置没有被选择，就可以进行选择
            if (!st[i])
            {
                st[i] = true;
                path[i] = nums[u];
                //下一个数字存在且不重复，则可选择的位置是其余全部位置
                if (u + 1 < nums.size() && nums[u + 1] != nums[u])
                    dfs(nums, u + 1, 0);
                //否则，只能选择之后的空位置，避免重复
                else
                    dfs(nums, u + 1, i + 1);
                //恢复现场（要么dfs状态参数改变、要么恢复位置）
                st[i] = false;
            }
    }

};
