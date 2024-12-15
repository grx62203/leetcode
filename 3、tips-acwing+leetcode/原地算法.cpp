283.移动零
844.比较含退格的字符串
977.有序数组的平方



--------------------------移除数组指定项目-------------------------------------
--------------------------数组缺失的第一个正数---------------------------------
--------------------------旋转图像--------------------------------------------
--------------------------交换012---------------------------------------------
--------------------------删除有序数组的重复元素-------------------------------




--------------------------移除数组指定项目-------------------------------------
1、原地哈希
for (int i = 0; i < nums.size(); i ++ )
	if (nums[i] != val)   nums[k ++ ] = nums[i];
2、双指针
 while (left < right) {
	if (nums[left] == val) {
		nums[left] = nums[right - 1];
		right--;
	} else 	left++;
}
3、暴力枚举
for (int i = 0; i < size; i++) {
	if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
		for (int j = i + 1; j < size; j++) {
			nums[j - 1] = nums[j];
		}
		i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
		size--; // 此时数组的大小-1
	}
}


--------------------------数组缺失的第一个正数---------------------------------
将数组中的元素的值  看作当前数组的下标，然后操作这个下标位置的值， 用新的nums来判断 旧数组中元素的大小满足的性质
（这里不判断0，所以需要将 1 对应为 下标 0）
操作：
1、桶排序
	将 1 放到 nums[0]，2放到 nums[1]、、、、       
		==找到第一个 num[i] ！= i  的位置 返回 i+1 就是不存在的最小正数
		//0-n的正数，最后的结果是能回到重定位位置的都回去了，回不去的那个下标，说明那个下标对应正数不存在
        for (int i = 0; i < n; i ++ ) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]])
                //将数nums[i] 交换到下标nums[i]对应的位置
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < n; i ++ )
            if (nums[i] != i)
                return i + 1;
        return n + 1;

2、原地哈希
	将 nums[i-1] 置为 -1，                    
	 	==找到第一个不为-1 的位置i ，返回 i+1   就是 不存在的最小正数
	 	//将小于n的正数 化为下标   1对应0、2对应1、、、、，将正数重定位位置的数组值化负
        //那么没有化负的数组值下标对应的正数（i+1）也就是没有被重定向，也就是没有出现过
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n)   nums[num - 1] = -abs(nums[num - 1]); 
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)   return i + 1;
        }
        return n + 1;


--------------------------旋转图像--------------------------------------------
1、规律
顺时针 90： 主对角线（从左上到右下）翻转，然后从中间水平反转
逆时针 90： 主对角线翻转，然后从中间上下翻转
顺时针180和逆时针180 都是先主对角线翻转，然后副对角线翻转
2、按圈四分交换四个位置




--------------------------交换012---------------------------------------------
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
1、单指针
2、多指针
 		for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            //把0交换到最前面
            if (nums[i] == 0) swap(nums[i ++ ], nums[j ++ ]);
            //把2交换到最后面
            else if (nums[i] == 2) swap(nums[i], nums[k -- ]);
            else i ++ ;
        }



--------------------------删除有序数组的重复元素-------------------------------
1、每个只出现一次
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i ++ )
            if (!i || nums[i] != nums[i - 1])
                nums[k ++ ] = nums[i];//将每次与前一个不一样的重新放到前面，形成新的数组，k先用后增，得长度
        return k;
    }
};
2、每个只出现两次
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;//原地算法的新下标
        for (auto x: nums)
            //前两个添加、如果这个数和前面两个有一个不一样的话就添加
            if (k < 2 || (nums[k - 1] != x || nums[k - 2] != x))
                nums[k ++ ] = x;
        return k;
    }
};
3、每个只出现k次
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return process(nums,1);
    }
    int process(vector<int>& nums,int k){
        int idx = 0;
        for(auto x : nums){
            if(idx < k || nums[idx - k] != x){
                nums[idx++] = x;
            }
        }
        return idx;  
    }
};
class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;
        for(auto num : nums)
            if(len < k || nums[len-k] != num)
                nums[len++] = num;
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }
};



