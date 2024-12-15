/*
一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。

我们将这样的一种表示称为正整数 n 的一种划分。

现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示总划分数量。

由于答案可能很大，输出结果请对 109+7 取模。

数据范围
1≤n≤1000
*/

//分治
//状态表示：
//f[n][m]表示n的m划分

LL solve(int n , int m ){  //n的m划分,将n分成m组数的和
    //如果n <= 1    显然只能分成一组 
    //如果m == 1    显然只能分成一组
    if( n == 1 || m == 1)    return 1 ;

    //如果n > m 
    //包含m：solve(n-m,m)
    //不包含m: solve(n-m , m-1 );
    if( n > m ) return (solve(n-m,m)+solve(n,m-1))%mod;

    //如果n < m , solve(n,m) == solve(n,n)
    if(n < m )  return solve(n,n)%mod ; 

    //如果包含n==m,总数 = 包含n + 不包含n的划分,即n的m-1划分
    if(n == m ) return  (1+solve(n,m-1))%mod ;

}

//C++ 代码

#include <iostream>

using namespace std;

const int mod = 1e9+7;

const int N = 1010;

int f[N][N] ;
int main()
{
    int n ; 
    cin >> n ; 

    for(int i = 1 ; i <= n ; i++)
        f[1][i] = f[i][1] = 1;     

    for(int i = 2 ; i <= n ; i++ ){
        for(int j = 2; j <= n ; j++ ){
            if(i == j)  f[i][j] = (1+f[i][j-1])%mod ;
            else if(i > j)   f[i][j] = (f[i-j][j]+f[i][j-1])%mod ;
            else             f[i][j] = f[i][i]%mod; 
        }
    }

    cout << f[n][n] << endl;

    return 0;
}