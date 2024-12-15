/*
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

**说明**：所有供暖器都遵循你的半径标准，加热的半径也一样。

 
*/
1、将房屋和暖气的位置分别从小到大排序。
2、假设得到了加热半径 r，即可在 O(n+m)的时间内，判断是否所有的房屋都得到了暖气，
具体为，逐一枚举房屋，然后判断是否有暖气覆盖，由于房屋和暖气的坐标都是单调的，
所以第 i+1个房屋不会使用坐标小于第 i 个房屋的暖气位置。
3、加热半径也是单调的，故可以使用二分来加速寻找最小的半径。

class Solution {
public:
    //检查mid条件下是否满足可以覆盖所有的房子
    bool check(int r, const vector<int>& houses, const vector<int>& heaters) {
        int n = heaters.size();
        //遍历所有房子是否可以用mid满足覆盖
        for (int i = 0, j = 0; i < houses.size(); i++) {
            while (j < n && abs(houses[i] - heaters[j]) > r) j++;
            //从前往后寻找可以在mid条件下覆盖当前房子的供暖器，直到找到或者超过供暖器的数量
            //表示当不可以覆盖到时j就一直向后走为的就是得到第一个可以覆盖i的j
            if (j == n)     return false;
            //当j超过供暖器数量的时候，就表示mid不行
        }
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        if (houses.size() == 0)
            return 0;

        int l = 0, r = max(*houses.rbegin(), *heaters.rbegin());
        //找右区间的左边界--二分模板
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, houses, heaters))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
