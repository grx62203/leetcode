/*
给你两个整数数组 `persons` 和 `times` 。在选举中，第 `i` 张票是在时刻为 `times[i]` 时投给候选人 `persons[i]` 的。

对于发生在时刻 `t` 的每个查询，需要找出在 `t` 时刻在选举中领先的候选人的编号。

在 `t` 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

实现 `TopVotedCandidate` 类：

- `TopVotedCandidate(int[] persons, int[] times)` 使用 `persons` 和 `times` 数组初始化对象。
- `int q(int t)` 根据前面描述的规则，返回在时刻 `t` 在选举中领先的候选人的编号。
*/
class TopVotedCandidate {
public:
    vector<int> win;//记录一长串从 某时刻开始每一个时刻 票数最多的人
    vector<int> times;//按时间投票给谁了

    TopVotedCandidate(vector<int>& persons, vector<int>& _times) {
        int n = persons.size();//候选人的数量
        win.resize(n);
        times = _times;
        vector<int> sum(n + 1);//记录每一个候选人当前的票数是多少。sum[0]、sum[1]代表两个人，容器中存储的值是当前的票数

        int maxc = 0, maxp;//表示票数最多的票数、人
        for (int i = 0; i < n; i ++ ) {
            int p = persons[i];//表示当前被投票人的编号
            if ( ++ sum[p] >= maxc) {//如果当前票数大于已经记录的最大票数，便更新
                maxc = sum[p];//更新编号是p的得票
                maxp = p;
            }
            win[i] = maxp;//当前的人记下来。是一个数组，记录一长串从 某时刻开始每一个时刻 票数最多的人
        }
    }

    int q(int t) {
        int k = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        //函数是可以严格二分出  大于当前数的最小数。
        //再减去初始迭代器，得到编号。
        //二分到投票时刻之间，就需要找到这个时间段的前一时刻
        return win[k];
    }
};