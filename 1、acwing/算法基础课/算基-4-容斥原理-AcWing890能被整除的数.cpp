/*
给定一个整数 n 和 m 个不同的质数 p1,p2,…,pm。

请你求出 1∼n 中能被 p1,p2,…,pm 中的至少一个数整除的整数有多少个。

输入格式
第一行包含整数 n 和 m。

第二行包含 m 个质数。

输出格式
输出一个整数，表示满足条件的整数的个数。

数据范围
1≤m≤16,
1≤n,pi≤109
*/
/*
1、求能被每个质数整除的范围 的  并集的 方案数
2、总公式 = 每个单独的结果  -  每两个的并集   +   每三个的并集   -  每四个的并集   +   -   +    唯一n个的并集
3、y总代码没有一个一个接着来求
	将每个质因子表示为 0、1 两种状态来确定是否选择
	枚举从1 开始 到 000001 到  000011  到  111111 的所有状态，也就是任意搭配（单独的结果、每两个、每三个、每四个、、、唯一一个）
		然后枚举m位
			数清楚当前状态对应的质因子p、对应的集合个数，累计质因子个数的乘积t、累计当前状态中集合的数量s
			如果这个t 可以整除1-n中的数
				那么分集合个数s来 在答案上累加 当前状态中 p的乘积t对应的整除个数
*/


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 20;

int p[N];//存储质数 


int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i ++ ) cin >> p[i];

    int res = 0;
	//枚举从1 到 1111...(m个1)的每一个集合状态, (至少选中一个集合)
    for (int i = 1; i < 1 << m; i ++ )//枚举到 2^m
    {
        int t = 1；                    //选中集合对应质数的乘积
        int s = 0;                     //选中的集合数量
        //枚举当前状态的每一位
        for (int j = 0; j < m; j ++ )//枚举m位
        	//如果当前集合状态 i 中的 第 j 位 是 1，说明第j位 被算进t里面了，也就是选中了一种状态，毕竟如果是并集的话需要将质数相乘为t
            if (i >> j & 1)          
            {
            	//乘积大于n, 则n/t = 0, 跳出这轮循环，也就是这个集合状态不被考虑，不在总公式里面
                if ((LL)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                t *= p[j];    //说明第j位 被算进t里面了,也就是多个质因子相乘得p
                s ++ ;        //累加这个集合状态对应得集合数量，来判定  每个数量得集合前面得正负号
            }

        if (t != -1)
        {
            if (s % 2) res += n / t;         //偶数个集合
            else       res -= n / t;         //奇数个集合
        }
    }

    cout << res << endl;

    return 0;
}





//其他解决方法-DFS

#include <iostream>

using namespace std;

typedef long long LL;
const int N = 20;

LL p[N];
LL num=1, cnt;
LL res;
LL n, m;

void dfs(int x)
{
    if(x==m)
    {
        if(cnt==0 || num>n)
            return;
        if(cnt%2)
            res+=n/num;
        else
            res-=n/num;
        return;
    }
    if(num>n)
        return;
    dfs(x+1);

    cnt++;
    num*=p[x];
    dfs(x+1);
    cnt--;
    num/=p[x];
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> p[i];
    dfs(0);
    cout << res;
    return 0;
}