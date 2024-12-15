[1000桶水，其中一桶有毒，猪喝毒水后会在15分钟内死去，想用一个小时找到这桶毒水，至少需要几头猪？ - 知乎 (zhihu.com)]
(https://www.zhihu.com/question/60227816/answer/1274071217)

/*
有` buckets` 桶液体，其中 **正好** 有一桶含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。不幸的是，你只有 `minutesToTest` 分钟时间来确定哪桶液体是有毒的。

喂猪的规则如下：

1. 选择若干活猪进行喂养
2. 可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
3. 小猪喝完水后，必须有 `minutesToDie` 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。
4. 过了 `minutesToDie` 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。
5. 重复这一过程，直到时间用完。

给你桶的数目 `buckets` ，`minutesToDie` 和 `minutesToTest` ，返回在规定时间内判断哪个桶有毒所需的 **最小** 猪数。
*/

class Solution {
public:
    int poorPigs(int n, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie;
        //k轮回合
        return ceil(log(n) / log(k + 1));
    }
};




【C++】emmm，根据信息论算了下，但是题目过程中的证明还是要学一下

从信息论角度来说，n只猪m轮

猪最多有(m+1)^n种状态（每只猪都分为在某个阶段死或最后都没死）则信息熵为n*log(m+1)

待求的k桶水有1桶有毒有k种状态，其信息熵为log(k)

因此，在n*log(m+1)>=log(k)时 可能 有最优方案，
即 n >= log(k) / log(m+1) 即 n = ceil( log(k) / log(m+1) )

具体实现方法可以把桶编号转为对应的m+1进制，猪数n即为对应的位数，
让每只猪对应一位，然后对应的时间喝对应位数的水（即1号猪第2分钟喝 第1位值为1(2-1，转化一下) 的水 ）
记录所有猪死亡的状态（时间）就可以根据m+1进制转化回有毒的桶的编号了

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
题目中计算证明的过程，大致就是首先设计一种喂的方案，使得每次的死亡能表达的信息最大化，
根据每种死亡方案，都可以推出一个类似的子问题，就变成了一个递推的问题。然后可以直接记忆化优化为动态规划，或者根据表达式化简出数学公式