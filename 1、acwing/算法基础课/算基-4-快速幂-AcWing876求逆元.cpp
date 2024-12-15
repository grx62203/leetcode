/*
给定 n 组 a,p，其中 p 是质数，求 a 模 p 的乘法逆元，若逆元不存在则输出 impossible。
注意：请返回在 0∼p−1 之间的逆元。

乘法逆元的定义
1、如果 a * b % m = 1,则我们称b为a关于模为m的乘法逆元，当m为质数的时候，a关于m的乘法逆元 为 b = a^(m-2)
2、找到e,使得d*e除以(p-1)*(q-1)的余数为1，e就是d关于(p-1)*(q-1)得乘法逆元
*/
/*
一、本题就是求一个b = a^(m-2)，不涉及到具体解逆元
a与m互质的时候，才存在逆元
当m是质数的时候解逆元的方法：
    b = a^(m-2)，快速幂
当m不是质数的时候解逆元的方法：（ps1）（ps2）
    1、可以用 inv(a) = a^p % m 求,其中p为euler(a)-1,其中euler(x)为欧拉函数，代表小于x的正整数中和x互质的数的个数
    2、用exgcd可以求出aX+bY=gcd(a,b)=1的解。设解为X=x0,Y=y0,则a * x0 = 1 - b * y0，则a * x0 % b = 1，故x0是a关于b的乘法逆元
二、快速幂如果爆longlong得话，需要一个快速乘（ps3）
四、返回答案得注意
    我们令x = x0,则x是答案，但x可能是负数，我们可以进行下面的操作，是x成为小于b的满足条件的正整数：x = ( (x % b) + b ) % b;
五、C = X^d mod n，则C是加密后的密文。当收到密文C时，可以使用私钥解开，计算公式为：X = C^e mod n。
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//快速幂a、p-2、p模板
LL qmi(int a, int b, int p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, p;
        scanf("%d%d", &a, &p);
        if (a % p == 0) puts("impossible");
        else printf("%lld\n", qmi(a, p - 2, p));//求取a^(p-2),要求p一定是质数
    }

    return 0;
}



//ps1：欧拉函数求逆元
//1、用欧拉函数公式求欧拉函数p，再求 p = oula(p) - 1
//2、再用快速幂               求 逆元 = a ^ p % m 
    


//ps2：exgcd方法求逆元
#include <iostream>
#include <iomanip>
using namespace std;
#define LL long long
void exgcd(LL a,LL b,LL &x,LL &y,LL &d) 
{
 if(b==0)
    {
        d = a, x = 1,y = 0;
  return;
    }
    exgcd(b,a%b,y,x,d);
    y -= (a/b)*x;
}
LL getInv(LL a,LL mod,LL &g)
{
    LL x,y,d;
    exgcd(a,mod,x,y,d);
    g = d;
 return (x%mod+mod)%mod;
}
int main()
{
    LL x,mod;
 cout<<"求X关于mod的乘法逆元\n请输入X,mod: ";
 while(cin>>x>>mod)
    {
        LL g;
        LL inv = getInv(x,mod,g); 
  if(g!=1)
        {
   printf("%lld和%lld不互质，没有逆元！\n\n请继续输入X,mod(ctrl z to exit): ",x,mod);
   continue;
        }
  printf("%lld关于%lld的逆元为：%lld\n",x,mod,inv);
  printf("%lld * %lld %% %lld = %lld\n\n请继续输入X,mod(ctrl z to exit): ",x,inv,mod,x*inv%mod);  
    } 
 
 
 return 0;
}


//ps3：快速幂爆longlong
LL fast_product(LL a,LL b,LL mod)//快速乘
{
    LL ans = 0;
    while(b)
    {
        if(b&1) ans = (ans+a)%mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return ans;
} 
LL fast_pow(LL a,LL b,LL mod)//快速幂
{
    LL ans = 1;
    while(b)
    {
        if(b&1) ans = fast_product(ans,a,mod);
        a = fast_product(a,a,mod);
        b>>=1;      
    } 
    return ans;
}

