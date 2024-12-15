/*
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        int k = 0;
        while (k < a.size() && a[k][1] < b[0]) res.push_back(a[k ++ ]); // 左边完全没交集的部分

        if (k < a.size()) {
            b[0] = min(b[0], a[k][0]);                                  // 找到合并新区间最小左端点
            while (k < a.size() && a[k][0] <= b[1])                     // 找到可以合并的若干区间，然后得最大右端点
                b[1] = max(b[1], a[k ++ ][1]);
        }
        res.push_back(b);

        while (k < a.size()) res.push_back(a[k ++ ]);                   // 右边完全没交集的部分
        return res;
    }
};
