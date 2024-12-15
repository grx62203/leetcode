/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

*/
//32ms
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        if (a.empty()) return res;

        sort(a.begin(), a.end());
        int l = a[0][0], r = a[0][1];
        for (int i = 1; i < a.size(); i ++ ) {
            //前后无法合并
            if (a[i][0] > r) {
                res.push_back({l, r});
                l = a[i][0], r = a[i][1];
            } 
            //合并就是合并区间右端点
            else r = max(r, a[i][1]);
        }
        res.push_back({l, r});
        return res;
    }
};