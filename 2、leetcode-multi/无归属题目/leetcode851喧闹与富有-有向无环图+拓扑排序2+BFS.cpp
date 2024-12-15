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

我的笔记： 拓扑排序

首先确定方向是有钱指向没钱。

第一步，找到最有钱的人（不止一个），因为比最有钱的更有钱的人是不存在的，所以最有钱的人ans就是他自己，因此要统一设置默认值ans[x] = x 。

第二步，把最有钱的人放入队列，遍历队列
把最有钱的人quiet和对应的第二有钱人（不止一个）对比，如果最有钱的人quiet更小，就更新第二有钱人的ans为最有钱人。
对于一个第二有钱人，如果比他更有钱的人都遍历完了，那么第二有钱人就要升级为最有钱人，放入队列中，进行下一次遍历。

//找没钱的，从大到小
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>>    g(n);
        vector<int>            inDeg(n);

        //拓扑排序初始化模板
        for (auto &r : richer) {
            g[r[0]].emplace_back(r[1]);// 0 是有钱的  1 是没钱的
            ++inDeg[r[1]];             // 1 是没钱的，每添加一条边， 没钱的就 ++
        }

        vector<int> ans(n);//存储答案
        iota(ans.begin(), ans.end(), 0);//首先将所有人的答案   预置为  自身的下标
        // iota() 函数模板会用连续的 T 类型值填充序列。前两个参数是定义序列的正向迭代器，第三个参数是初始的 T 值

        queue<int> q;//序列存储  有钱人在前
        //找到  无法互相判断大小的  最大 的一批， 也就是有向图的  初始入点s
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.emplace(i);
            }
        }

        //有钱人在前，没钱人在后，遍历更穷的人（将当前人赋予更穷的人ans）
        while (!q.empty()) {
            int x = q.front();//从 有钱人开始
            q.pop();
            //遍历比当前人穷的人s
            for (int y : g[x]) {
                //把当前有钱的人A的quiet和对应的没钱人B（不止一个）对比，如果A的quiet更小，就更新B的ans为A。
                if (quiet[ans[x]] < quiet[ans[y]])  ans[y] = ans[x]; //有可能真正答案是当前人本身
                //先 -1，再判断 下位y 的标记，如果标记降为 0，那么代表 没有人比y更有钱了，可以开始从它这里迭代，加入队列     
                if (--inDeg[y] == 0) {
                    q.emplace(y);
                }
            }
        }
        return ans;
    }
};
