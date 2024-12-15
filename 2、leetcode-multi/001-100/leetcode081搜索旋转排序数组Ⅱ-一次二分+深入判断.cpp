/*
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

你必须尽可能减少整个操作步骤。
*/

/*
和 LeetCode 33. Search in Rotated Sorted Array 一样，我们观察数组具有怎样的性质。
不难看出当nums[mid]大于或者小于nums[r]的时候我们依然可以判断出中点是在左半边还是右半边，
不同的地方在于当nums[mid]等于nums[r]的时候我们不能确定中点的位置，
但此时依然可以缩小区间，这里我们直接让右边界r减一就好了。
原因在于将nums[r]排除出去依然可以保证答案仍在区间内因为我们有mid < r && nums[mid] == nums[r]。
*/
//4ms右区间的左端点
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[r]) {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid;
            } else if (nums[mid] > nums[r]) {
                if (target <= nums[mid] && target >= nums[l]) r = mid;
                else l = mid + 1;
            }
            else r -- ;//有了重复，此时无法判断左右区间，可以缩小r，再来一次
        }
        return nums[l] == target;
    }
};
