/*
整数数组 `nums` 按升序排列，数组中的值 **互不相同** 。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,5,6,7]` 在下标 `3` 处经旋转后可能变为 `[4,5,6,7,0,1,2]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，如果 `nums` 中存在这个目标值 `target` ，则返回它的下标，否则返回 `-1` 。

 

**示例 1：**
 
```
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])     r = mid-1;
                else                                             l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])     l = mid +1;
                else                                             r = mid -1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[0]) { // mid 在数组前半部分。
                if (target > nums[mid])
                    // 可以推出 target 的值一定大于 nums[0]，target 只可能在 [mid + 1, r] 中。
                    l = mid + 1;
                if (target < nums[0])
                    // 可以推出 target 的值一定小于 nums[mid]，target只可能在 [mid + 1, r] 中。
                    l = mid + 1;
                if (target <= nums[mid] && target >= nums[0])
                    // 此时 target 的值处于 nums[0] 和 nums[mid] 中，故可能在 [l, mid] 中。
                    r = mid;
            } else { // mid在数组后半部分
                if (target >= nums[0])
                    // 可以推出 target 的值一定大于 nums[mid]，target只可能在 [l, mid] 中。
                    r = mid;    
                if (target <= nums[mid])
                    // 可以推出 target 的值一定小于 nums[0]，target只可能在 [l, mid] 中。
                    r = mid;
                if (target > nums[mid] && target < nums[0])
                    // 此时 target 的值处于 nums[0] 和 nums[mid] 中，故可能在 [mid + 1, r] 中。
                    l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};