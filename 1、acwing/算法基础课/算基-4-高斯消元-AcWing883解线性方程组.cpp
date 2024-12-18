/*
输入一个包含 n 个方程 n 个未知数的线性方程组。
方程组中的系数为实数。

求解这个方程组。
下图为一个包含 m 个方程 n 个未知数的线性方程组示例：

9a504fc2d5628535be9dcb5f90ef76c6a7ef634a.gif

输入格式
第一行包含整数 n。
接下来 n 行，每行包含 n+1 个实数，表示一个方程的 n 个系数以及等号右侧的常数。

输出格式
如果给定线性方程组存在唯一解，则输出共 n 行，其中第 i 行输出第 i 个未知数的解，结果保留两位小数。
如果给定线性方程组存在无数解，则输出 Infinite group solutions。
如果给定线性方程组无解，则输出 No solution。

*/
/*
1、gauss()高斯消元，答案存于a[i][n]中，0 <= i < n
    for 枚举列（正对角线）
        for 枚举包括当前行下面的若干行--------------------------找绝对值最大的行，赋值于t
            if 如果当前这一列的最大数都是 0 ，那么所有数都是 0，就没必要去算  
        for 枚举n次-------------------------------------------将绝对值最大的 一整行 换到最顶端
        for 枚举换行之后的新行的所有列单位----------------------将当前新行的首位变成1，倒序 
        for 枚举换行之后的新行下面的所有行----------------------用当前行将下面所有的列消成0
            if 这一行的第一个元素（对应当前列参）不为0
                for 枚举某一行的后段所有列参，从后往前----------用选中行的列参 将 首列参不为0的行的所有列参 做a[r][j]倍差，将枚举行便成了变量更少的新的方程
*/



#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;  //判断浮点数时候的判断标志

int n;
double a[N][N];

//高斯消元模板
int gauss()  // 高斯消元，答案存于a[i][n]中，0 <= i < n
{
    int c, r;//列、行
    //枚举列（正对角线）
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        //枚举包括当前行下面的若干行
        for (int i = r; i < n; i ++ )                           // 1、找绝对值最大的行，赋值于t
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue; // 如果当前这一列的最大数都是 0 ，那么所有数都是 0，就没必要去算了，因为它的约束方程，可能在上面几行            
            //浮点数判断是否为 0 
            //fabs 与abs不一样，返回浮点数

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);  // 2、将绝对值最大的 一整行 换到最顶端
        //枚举换行之后的新行的所有列单位
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 3、将当前新行的首位变成1，倒序
        //枚举换行之后的新行下面的所有行
        for (int i = r + 1; i < n; i ++ )                       // 4、用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)                            // 如果 当前位置不是0
            	// 枚举从后往前，当前行的后段每个数字，这样就能保证第一个数字是 a[i][c] -= 1*a[i][c];  
                for (int j = n; j >= c; j -- )                        
                    a[i][j] -= a[r][j] * a[i][c];               // 主要是为了将对应的第一个元素化 0 ，其他跟随倍数
                	// 每个数字，都减去 对应列 * 行首非0的数字
        r ++ ;
    }

    if (r < n)//5、方程个数小于 n ，没有唯一解
    {
    	// 因为已经是阶梯型，所以 r ~ n-1 的值应该都为 0，
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)      //如果 出现了非0，则无解
            // a[i][n] 代表 b_i ,即 左边=0，右边=b_i,0 != b_i, 所以无解
                return 2; // 无解
        return 1;         // 否则， 0 = 0，就是r ~ n-1的方程都是多余方程有无穷多组解
    }


    //6、遍历每一行求唯一解 ↓，从下往上回代，得到方程的解
    for (int i = n - 1; i >= 0; i -- )
    	//假设是求取Xn，不进入循环直接a[i][n]就是等式右边的答案
    	//假设是求取X8，需要一次次减去X9的值，减去X10的值，直到减去Xn，结果存储在a[8][n]
    			      //x9就是 a[8][9]*a[9][n]  = 第八个方程中 X9的系数 *  存放的X9的结果
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];//方程的右值 减去当前行后面 若干x*x参数。便有当前行第一个x 的结果，也就是第一个x对应的解
            //因为只要得到解，所以只用对 b_i 进行操作，中间的值，可以不用操作，因为不用输出
    return 0; // 有唯一解
}


int main()
{
    //输入方程
    scanf("%d", &n);  
    for (int i = 0; i < n; i ++ )        //列 有n列
        for (int j = 0; j < n + 1; j ++ )//行 多存一个b
            scanf("%lf", &a[i][j]);

    int t = gauss();

    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else
    {
        for (int i = 0; i < n; i ++ )
        {
            if (fabs(a[i][n]) < eps) a[i][n] = 0;  // 去掉输出 -0.00 的情况
            printf("%.2lf\n", a[i][n]);            //保留两位小数的正确写法
        }
    }

    return 0;
}