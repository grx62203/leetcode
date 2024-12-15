
----------------------------------------------------------------------------
--------------------------多集合二分leetcode004------------------------------





--------------------------多集合二分leetcode004------------------------------
一、需要砍掉前k-1个，返回第k个元素
	调序保证前一个比后一个短
	边界条件        //特例便是数组1为空，数组2的下标为k-1的便是中位数
	递归结束，正好砍掉了k-1个数，接下来最小的便是中位数了
	防止越界        //数组1先结束，所以要防止si超过nums1。size（）  轮到哪一个数组，哪一个数组再k对半增加索引
	如果此时数组1的数大，砍掉数组2的前面部分
	反之，砍掉数组1的前面部分，这个时候可能会有变换起始位置越界、将数组1砍完也没结束的情况
二、	主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
    这里的 "/" 表示整除
    nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
    nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
    取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
    这样 pivot 本身最大也只能是第 k-1 小的元素
    如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
    如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
    由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
		边界情况-有以下三种情况需要特殊处理：
		如果 A[k/2−1] 或者 B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。在这种情况下，我们必须根据排除数的个数减少 k的值，而不能直接将 k 减去 k/2。
		如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 k小的元素。
		如果 k=1，我们只要返回两个数组首元素的最小值即可。
三、动态规划+等分数组+看不懂