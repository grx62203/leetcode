/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

**说明**：所有供暖器都遵循你的半径标准，加热的半径也一样。
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            int curDistance = abs(houses[i] - heaters[j]);//从第一个房子与第一个供暖器开始
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
            //当j是最后一个供暖之前，且 j到i的距离 大于 j+1 到i的距离，那么就进入循环，代表j+1更有可能
            //停止的时候，正好 j与i的距离就是当前房子i 的最优 距离min，
                j++;
                curDistance = min(curDistance, abs(houses[i] - heaters[j]));//正好 j与i的距离就是当前房子i的最优距离
            }
            ans = max(ans, curDistance);//再求所有房子的最优距离max
        }
        return ans;
    }
};