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

//找有钱的，从小到大
class Solution {
public:
    vector<vector<int>> g;//存放当前索引i作为入的出点的集合
    vector<int> w;        //存放quiet
    vector<int> ans;      //结果

    void dfs(int u) {
        if (ans[u] != -1) return ;//如果计算过，return
        ans[u] = u;//首先可返回自己
        //遍历所有能到达的人，也就是更有钱的人
        for (auto v: g[u]) {
            dfs(v);//dfs
            if (w[ans[u]] > w[ans[v]])
                ans[u] = ans[v];//在更有钱的人之间找最小的quiet值
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        w = quiet;
        g.resize(n);      //邻接表 
        ans.resize(n, -1);//-1 表示没有被搜索过

        //拓扑排序的初始化模板，存有向无环图的入点-出点
        for (auto& e: richer) {
            int a = e[0], b = e[1];//0 是出、1 是入，  比较特殊
            g[b].push_back(a);
            //g[e[1]].emplace_back(e[0]);
        }

		//搜索每一个人能达到出点，也就是一直找比当前人更有钱的，然后比较quiet值
        for (int i = 0; i < n; i ++ ) dfs(i);

        return ans;
    }
};
