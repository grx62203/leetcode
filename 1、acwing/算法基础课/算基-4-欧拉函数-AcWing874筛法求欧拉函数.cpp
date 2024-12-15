/*
给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和
*/
//类似于线性筛法求质数
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1000010;

int primes[N], cnt;	//存储质数，且计数
bool st[N];         //筛掉的时候true
int euler[N];       //储存欧拉函数

//筛法求欧拉函数模板
void get_eulers(int n)
{
    euler[1] = 1;

    //线性筛质数模板 改造
    for (int i = 2; i <= n; i ++ )//每一次时间复杂度是O（n）
    {
    	//==对质数求欧拉函数
        if (!st[i])//如果没有被筛掉，存储，累加计数
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;   //质数的欧拉函数就是 质数-1
        }
        //==对非质数求欧拉函数
        for (int j = 0; primes[j] <= n / i; j ++ )//从小到大遍历每个质数，i不变
        {

            int t = primes[j] * i;
            st[t] = true;
            //删掉质数与当前数的乘积，恰好是可以对每个合数都只删一次，也就是pj*i第一次出现的时候，pj是pj*i的最小质因子
            if (i % primes[j] == 0)//遍历到了pj 第一次成为最小质因子的对象 i，退出
            {
                euler[t] = euler[i] * primes[j];//公式一，此时pj是i的最小质因数，为了避免 pj*i 之后的被 pj计算，所以break
                //pj 是 i    的质因子
                //pj 是 pj*i 的质因子
                //i  肯定不是    质数
                //所以pj*i 与 i 的质因数相同
                //所以pj*i 的欧拉函数 = i的欧拉函数 * pj
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);//公式二，与公式一 只执行一个，都是求每一个非质数的欧拉函数
            //pj 不是 i     的质因子
            //pj 是  pj*i  的质因子
            //i  不确定是    质数
            //所以pj*i 比 i 多一个质因子 是 pj
            //所以pj*i 的欧拉函数 = i的欧拉函数 * （pj-1）  <pj*i的欧拉函数公式中，(pj-1)/pj 的分母项被消掉了>
        }
    }
}
int main()
{
    int n;
    cin >> n;

    get_eulers(n);

    //累加前n项和得欧拉函数之和
    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res += euler[i];

    cout << res << endl;

    return 0;
}