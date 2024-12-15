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
            //首先判断是不是和 所求点重合，标记重合数量
                sameCnt++;
                continue;
            }
            double degree = atan2(point[1] - location[1], point[0] - location[0]);
            //求取两个点的弧度，这个弧度 起始边是 x 正方向
            polarDegrees.emplace_back(degree);
            //将每个点 重新量化到弧度这一个有始有终的 线性范围（不过还需要补足，毕竟要转回来）
        }
        sort(polarDegrees.begin(), polarDegrees.end());//从小到大排序

        int m = polarDegrees.size();
        for (int i = 0; i < m; ++i) {
        	//后面补齐原来的 线性范围
            polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
        }

        int maxCnt = 0;
        int right = 0;
        double degree = angle * M_PI / 180;
        for (int i = 0; i < m; ++i) {
        	//开始滑动窗口，在 right 到达终点停止； 在 right 到达可见约束（转换为线性约束）的窗口右边停止（左边是集合元素的位置）
        	//每次进入for 的时候right从0开始
        	//right 只是一个计数 
            while (right < polarDegrees.size() && polarDegrees[right] <= polarDegrees[i] + degree) {
                right++;
            }
            maxCnt = max(maxCnt, right - i);//择优保留结果
        }
        return maxCnt + sameCnt;//same的点一定是在可见范围内
    }
};