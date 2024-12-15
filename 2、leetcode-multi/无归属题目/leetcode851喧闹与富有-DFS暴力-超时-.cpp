/*
有一组 `n` 个人作为实验对象，从 `0` 到 `n - 1` 编号，其中每个人都有不同数目的钱，
以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 `x` 的人简称为 "person `x` "。

给你一个数组 `richer` ，其中 `richer[i] = [ai, bi]` 表示 person `ai` 比 person `bi` 更有钱。
另给你一个整数数组 `quiet` ，其中 `quiet[i]` 是 person `i` 的安静值。
`richer` 中所给出的数据 **逻辑自恰**
（也就是说，在 person `x` 比 person `y` 更有钱的同时，不会出现 person `y` 比 person `x` 更有钱的情况 ）。

现在，返回一个整数数组 `answer` 作为答案，其中 `answer[x] = y` 的前提是，
在所有拥有的钱肯定不少于 person `x` 的人中，person `y` 是最安静的人（也就是安静值 `quiet[y]` 最小的人）。
*/

比x有钱或者同样富有的人里面，最安静的是j
quiet中x是下标，存储着j

//超时
class Solution {
public:
    void dfs(int& i, int& k, unordered_multimap<int,int> a, vector<int>& q, int& m){
        auto range = a.equal_range(i);
        for(auto it = range.first; it != range.second; ++it){
            int j = it->second;
            if(m > q[j]){
                m = q[j];
                k = j;    
            }
            dfs(j, k, a, q, m);
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //if(richer.empty()) return 0;

        unordered_multimap<int,int> a;
        for(auto& c : richer){
            a.insert({c[1], c[0]});
        }

        vector<int> goal;
        int n = quiet.size();
        for(int i = 0; i < n; i++){
            int k = i;
            int m = quiet[i];
            dfs(i, k, a, quiet,m);
            goal.push_back(k);
        }

        return goal;
    }
};