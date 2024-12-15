/*
给定 n 组 a,b,p，对于每组数据，求出  a^b mod p  的值。
*/
/*
反复平方法
现预处理
	a^2^0 mod p
	a^2^1 mod p
	a^2^2 mod p
	a^2^3 mod p
	a^2^4 mod p
	a^2^5 mod p
	a^2^6 mod p
然后将每一个a^k 化解为前面若干项的乘积
也就是将k化解为二进制表示
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


//快速幂abp模板
LL qmi(int a, int b, int p)
{
    LL res = 1 % p;//当p = 1 的时候结果不一样
    while (b)
    {
        if (b & 1) res = res * a % p; // & 1 取出末位判断，如果末位是1   res * a^2^i % p
        a = a * (LL)a % p;            //a^2^i 变为 a^2^(i+1) 下一项  其中LL是防止中间溢出
        b >>= 1;                      //除以2，更新末位
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }

    return 0;
}