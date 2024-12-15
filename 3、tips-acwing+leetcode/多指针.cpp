



--------------------------四数之和--------------------------------------------
--------------------------有序数组的平方---------------------------------------




--------------------------四数之和--------------------------------------------
//多指针-一次移动1个
for (int k = j + 1, u = nums.size() - 1; k < u; k ++ ) {
	if (k > j + 1 && nums[k] == nums[k - 1]) continue;
	while (k < u - 1 && nums[i] + nums[j] -target >= - nums[k] - nums[u - 1] ) u -- ;
	if (nums[i]+nums[j]-target==-nums[k]-nums[u]){
		res.push_back({nums[i], nums[j], nums[k], nums[u]});
	}
}
//多指针-一次移动2个
int left = j + 1, right = length - 1;
while (left < right) {
	int sum = nums[i] + nums[j] + nums[left] + nums[right];//溢出的可能性在前面被特判了
	if (sum == target) {
		res.push_back({nums[i], nums[j], nums[left], nums[right]});
		while (left < right && nums[left] == nums[left + 1])  left++;
		left++;
		while (left < right && nums[right] == nums[right - 1])  right--;
		right--;
	} 
	else if (sum < target) left++;
	else  right--;
}
//溢出的处理办法一
//while (u - 1 > k && nums[i] + nums[j] + nums[k] + nums[u - 1] >= target) u -- ;会溢出
while (k < u - 1 && nums[i] + nums[j] -target >= - nums[k] - nums[u - 1] ) u -- ;
//if (nums[i] + nums[j] + nums[k] + nums[u] == target){ 会溢出，需要修改
if (nums[i]+nums[j]-target==-nums[k]-nums[u]){
//溢出的处理办法二（溢出的可能性在前面被特判）
if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; 
if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)  continue; 
    if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)  break;
	if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)  continue; 




--------------------------有序数组的平方---------------------------------------
	vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }


