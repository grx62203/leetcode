/*
给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

 

**示例 1：**

```
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```

**提示：**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-106 <= nums1[i], nums2[i] <= 106`
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            //除以2d
            return (left + right) / 2.0;
        }
        else
        {
            //假设有2k-1个数，砍掉前k-1个数，剩下的最小的（第k个）便是中位数，即总的下标为k-1便是中位数
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }
	//需要砍掉前k-1个，返回第k个元素
    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        //调序保证前一个比后一个短
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        
        //先考虑边界条件        
        //特例便是数组1为空，数组2的下标为k-1的便是中位数，
        if (nums1.size() == i) return nums2[j + k - 1];
        
        //此时递归结束，正好砍掉了k-1个数，接下来最小的便是中位数了
        if (k == 1) return min(nums1[i], nums2[j]);
        
       	//防止越界
        //数组1先结束，所以要防止si超过nums1。size（）
        //轮到哪一个数组，哪一个数组再k对半增加索引
        //vector数组中size函数的返回值是size_type ，而 size_type 的类型是：unsigned int，min接受int型参数，所以需要强转
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2; 
        
        //如果此时数组1的数大，砍掉数组2的前面部分，下一次两个数组的开始位置就变成了i与j+k/2，下一次的砍数就变成了k-k/2-1个 
        if (nums1[si - 1] > nums2[sj - 1])   return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
        //反之，砍掉数组1的前面部分，这个时候可能会有变换起始位置越界、将数组1砍完也没结束的情况
        //else包括一种相等的情况，存在一种边界：nums1[]中的数不足k / 2个，那么此时si + sj < k，所以当前数就不是第k个数了。
        else    return findKthNumber(nums1, si, nums2, j, k - (si - i));
    }
};


class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            	// 边界情况-有以下三种情况需要特殊处理：
			//如果 A[k/2−1] 或者 B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。在这种情况下，我们必须根据排除数的个数减少 k的值，而不能直接将 k 减去 k/2。
			//如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 k小的元素。
			//如果 k=1，我们只要返回两个数组首元素的最小值即可。

            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            //递归结束
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];//相当第k/2-1个作比较，然后取第K个
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};

