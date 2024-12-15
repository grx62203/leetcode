/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

**说明**：所有供暖器都遵循你的半径标准，加热的半径也一样。
*/

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());//排序
        for (int house: houses) {//遍历房子
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();//返回大于这个房子的最小供暖器
            int i = j - 1;                                                               //得到小于这个房子的最大供暖器
            int rightDistance = j >= heaters.size() ? INT_MAX : heaters[j] - house;//为什么会下标越界？？？
            int leftDistance = i < 0 ? INT_MAX : house - heaters[i];
            //越界代表的是在第一个供暖器之前的和最后一个供暖器之后的房子，最前面的房子左距离和右距离取小，后面的房子也是
            //因此在取小的过程中要给虚无缥缈的最前和最后的距离一个值，得以 min函数
            int curDistance = min(leftDistance, rightDistance);
            //对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离
            ans = max(ans, curDistance);
        }
        return ans;
    }
};
