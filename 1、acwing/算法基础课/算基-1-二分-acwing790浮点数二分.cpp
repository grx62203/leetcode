/*
给定一个浮点数 nn，求它的三次方根。

输入格式
共一行，包含一个浮点数 nn。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 66 位小数。

数据范围
−10000≤n≤10000
*/
#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = -100, r = 100;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%.6lf\n", l);//printf一般默认保留六位小数的
    return 0;
}