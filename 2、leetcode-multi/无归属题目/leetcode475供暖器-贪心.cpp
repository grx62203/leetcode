/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

**说明**：所有供暖器都遵循你的半径标准，加热的半径也一样。
*/
1、将房屋和暖气的位置分别从小到大排序。
2、逐一枚举每个房屋，对于房屋 i，他使用暖气必定是距离他左右（如果有）最近的两个之一，
由于我们已经对坐标进行了排序，所以这个过程如算法 1 一样是单调的。
3、按照 2 的过程，随时更新半径的最大值r即可

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int r = 0;
        //枚举每个房子
        for (int i = 0, j = 0; i < houses.size(); i++) {
            if (abs(houses[i] - heaters[j]) > r) {
                while (j < n && heaters[j] < houses[i])   j++;
                //找到当前房子的右边最近供暖器
                if (j == n) //到了最后一个供暖器
                {
                    r = max(r, houses[i] - heaters[j - 1]);
                    j--;//???????
                } 
                else if (j == 0) //到了第一个供暖器
                {
                    r = max(r, heaters[j] - houses[i]);
                } 
                else //中间其他供暖器
                {
                    if (houses[i] - heaters[j - 1] < heaters[j] - houses[i])//如果左边最近的供暖器距离更小
                    {
                        r = max(r, houses[i] - heaters[j - 1]);
                        j--;//????????
                    } else                                                  //如果左边最近的供暖器距离更小
                        r = max(r, heaters[j] - houses[i]);
                }
            }
        }
        return r;
    }
};
