//快速乘法
1、
int fast_multiplication(int x,int y)
{
	ll ans;
	while(y)
	{
		if(y&1)//判断y是否为奇数,若是奇数，则直接加上数字
			ans+=x;
		y>>=1;
		x<<=1;
	}
}
2、
int fast_multiplication_with_mod(int x,int y,int mod)
{
	ll ans;
	while(y)
	{
		if(y&1)//判断y是否为奇数,若是奇数，则直接加上数字
			ans=(ans+x)%mod;
		y>>=1;
		x<<=1;
}
3、
int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
        if (B & 1) {
            ans += A;
        }
        A <<= 1;
    }
    return ans;
}
4、


//快速幂法
1、
int fast_pow(int x,int y)
{
	ll ans;
	while(y)
	{
		if(y&1)//判断y是否为奇数,若是奇数，则直接加上数字
			ans=ans*x;
		y>>=1;
		x*=x;
	}
}
2、
int fast_pow_with_mod(int x,int y,int mod)
{
	ll ans;
	while(y)
	{
		if(y&1)//判断y是否为奇数,若是奇数，则直接加上数字
			ans=(ans*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans%mod;
}
