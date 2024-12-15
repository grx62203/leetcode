/*
给你一个点数组 `points` 和一个表示角度的整数 `angle` ，你的位置是 `location` ，
其中 `location = [posx, posy]` 且 `points[i] = [xi, yi]` 都表示 X-Y 平面上的整数坐标。

最开始，你面向东方进行观测。你 **不能** 进行移动改变位置，
但可以通过 **自转** 调整观测角度。换句话说，`posx` 和 `posy` 不能改变。
你的视野范围的角度用 `angle` 表示， 这决定了你观测任意方向时可以多宽。
设 `d` 为你逆时针自转旋转的度数，那么你的视野就是角度范围 `[d - angle/2, d + angle/2]` 所指示的那片区域。
*/
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int sameCnt = 0;
        vector<double> polarDegrees;
        for (auto & point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                sameCnt++;
                continue;
            }
            double degree = atan2(point[1] - location[1], point[0] - location[0]);
            polarDegrees.emplace_back(degree);
        }
        sort(polarDegrees.begin(), polarDegrees.end());

        int m = polarDegrees.size();
        for (int i = 0; i < m; ++i) {
            polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
        }

        int maxCnt = 0; 
        double degree = angle * M_PI / 180;
        for (int i = 0; i < m; ++i) {
            auto it = upper_bound(polarDegrees.begin() + i, polarDegrees.end(), polarDegrees[i] + degree);
            //用于在指定范围内查找大于目标值的第一个元素的下标。
            int curr = it - polarDegrees.begin() - i;//得到可见范围的个数
            maxCnt = max(maxCnt, curr);//再择优
        }
        return maxCnt + sameCnt;
    }
};