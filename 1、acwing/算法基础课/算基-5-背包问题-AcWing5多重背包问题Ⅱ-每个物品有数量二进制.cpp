/*
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。
*/
/*
0、DP
    状态表示 f[j] 
        集合   
            从前i个物品选择，背包容量为j时所有的选法
            条件 （数目限制、体积限制）
                只从前i个选
                总体积不超过j
        属性   
            最大值
            (最小值)
            (数量)
    状态计算
        本质就是集合的划分
        一维优化 j 倒序 f[j] = max(f[j] , f[j - v[i]] + w[i]);--------------------------将每个物品的数量二进制分组，然后类01
    优化
        方程做等价变形
    遍历i，是遍历物品；遍历j，是遍历背包的容量，遍历k，是选择物品的条件，还需要判断物品的体积与剩余容量
    二维会存在不选的情况去用上一层初始化，或者有多个当前物品会合并到k=0的情况，但一维不存在
    二维化为一维的条件，且只有完全背包是反01
        a、f[i] 仅用到了f[i-1]层
        b、j与j-v[i] 均小于j，这样子就可以看为滚动数组倒序---若用到前一层的状态时,从大到小枚举, 反之从小到大哦   
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 12010, M = 2010;

int n, m;
int v[N], w[N];//逐一枚举最大是N*logS
int f[M];      // 体积<M

int main()
{
    cin >> n >> m;

    int cnt = 0;//分组的组别
    //将s分为二进制的表示 1+2+4+8++++   与  剩余数  若干组（二进制的前面几项的系数都是 1 ）
    for (int i = 1; i <= n; i ++ )
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;// 组别里面的个数
        while (k <= s)
        {
            cnt ++ ;       //组别先增加，前半部分组别由每个物品的数量s = 1 + 2 + 4 + 8 + 16 + 中的元素的数量决定，当累积k比剩余s大的时候，有剩余数量一组
            v[cnt] = a * k;//当前物品的当前组整体体积
            w[cnt] = b * k;//当前物品的当前组整体价值
            s -= k;        //当前物品的剩余数量s要减小
            k *= 2;        //当前物品的组别里的个数增加 1、2、4、8、16、32、64、、、
        }
        //当前物品的剩余数量形成的一组
        if (s > 0)
        {
            cnt ++ ;
            v[cnt] = a * s;//当前物品的最后一组整体体积
            w[cnt] = b * s;//当前物品的最后一组整体价值
        }
    }

    n = cnt;//枚举次数正式由个数变成组别数

    //一维优化(类01背包)
    for (int i = 1; i <= n; i ++ )//----------------遍历所有组
        for (int j = m; j >= v[i]; j -- )//---------遍历背包容积
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;

    return 0;
}


/*************************************************************************************/
思路一：

1、强行拆成01背包问题，改变n为重构的组数量

3、为什么最后一项会是f[i-1,j-(S+1)v]+Sw??

在完全背包中,通过两个状态转移方程：
f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w , f[i-1,j-2v]+2w , f[i-1,j-3v]+3w, .....)
f[i , j-v]= max(             f[i-1,j-v] , f[i-1,j-2v] + w, f[i-1,j-2v]+2w , .....)

通过上述比较，可以得到 f[ i ][ j ] = max(f[ i - 1 ][ j ],f[ i ][ j - v ] + w)。

再来看下多重背包,
f[i , j ] = max( f[i-1,j] ,f[i-1,j-v]+w ,f[i-1,j-2v]+2w ,..... f[i-1,j-Sv]+Sw, )
f[i , j-v]= max(           f[i-1,j-v] ,f[i-1,j-2v]+w, ..... f[i-1,j-Sv]+(S-1)w, f[i-1,j-(S+1)v]+Sw )

怎么比完全背包方程比较就多出了一项?
其实，一般从实际含义出发来考虑即可，这里是在分析f[i,j-w]这个状态的表达式，
首先这个状态的含义是 从前i个物品中选，且总体积不超过j-w的最大价值， 我们现在最多只能选s个物品，
因此如果我们选s个第i个物品，那么体积上就要减去 s * v,价值上就要加上s * w，那更新到状态中去就是 f[i - 1, j - v - s * v] + s * w。

那为什么完全背包不会有最后一项？
完全背包由于对每种物品没有选择个数的限制，所以只要体积够用就可以一直选，没有最后一项。

4、为什么不能用像完全背包一样去优化？
完全背包没有极限，但是多重背包有极限

5、二进制优化，它为什么正确，为什么合理，凭什么可以这样分？？

我们首先确认三点：

（1）我们知道转化成01背包的基本思路就是：判断每件物品我是取了你好呢还是不取你好。

（2）我们知道任意一个实数可以由二进制数来表示，也就是2^0~2^k其中一项或几项的和。

（3）这里多重背包问的就是每件物品取多少件可以获得最大价值。

分析：

如果直接遍历转化为01背包问题，是每次都拿一个来问，取了好还是不取好。那么根据数据范围，这样的时间复杂度是O(n^3),也就是1e+9，这样是毫无疑问是会TLE的。

假如10个取7个好，那么在实际的遍历过程中在第7个以后经过状态转移方程其实已经是选择“不取”好了。
现在，用二进制思想将其分堆，分成k+1个分别有2^k个的堆，然后拿这一堆一堆去问，我是取了好呢，还是不取好呢，
经过dp选择之后，结果和拿一个一个来问的结果是完全一样的，因为dp选择的是最优结果，而根据第二点任意一个实数都可以用二进制来表示，
如果最终选出来10个取7个是最优的在分堆的选择过程中分成了2^0=1,2^1=2,2^2=4,10 - 7 = 3 这四堆，
然后去问四次，也就是拿去走dp状态转移方程，走的结果是第一堆1个，取了比不取好，第二堆2个，取了比不取好，第三堆四个，取了比不取好，第四堆8个，取了还不如不取，最后依旧是取了1+2+4=7个。

Tip:参考博客

如果仍然不是很能理解的话，取这样一个例子:要求在一堆苹果选出n个苹果。我们传统的思维是一个一个地去选，选够n个苹果就停止。这样选择的次数就是n次

二进制优化思维就是：现在给出一堆苹果和10个箱子，选出n个苹果。将这一堆苹果分别按照1,2,4,8,16,.....512分到10个箱子里，那么由于任何一个数字x ∈[1,1024]
都可以从这10个箱子里的苹果数量表示出来，但是这样选择的次数就是 ≤10次 

/*************************************************************************************/

