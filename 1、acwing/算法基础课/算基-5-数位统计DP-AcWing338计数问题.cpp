 /*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中 0∼9 的出现次数。

例如，a=1024，b=1032，则 a 和 b 之间共有 9 个数如下：

1024 1025 1026 1027 1028 1029 1030 1031 1032

其中 0 出现 10 次，1 出现 10 次，2 出现 7 次，3 出现 3 次等等…

输入格式
输入包含多组测试数据。

每组测试数据占一行，包含两个整数 a 和 b。

当读入一行为 0 0 时，表示输入终止，且该行不作处理。

输出格式
每组数据输出一个结果，每个结果占一行。

每个结果包含十个用空格隔开的数字，第一个数字表示 0 出现的次数，第二个数字表示 1 出现的次数，以此类推。

数据范围
0<a,b<100000000
*/
/*
abcdefg
    求1在每一位上出现的次数（第几位是绝对位置）
        求1在第4位出现的次数
        1 <= xxx1yyy <= abcdefg 
    1、xxx = 000~abc-1,  0~999
    2、abc = xxx
        1. num[i] < x,  0       当d<1时，1不会出现
        2. num[i] == x, 0~efg   当d=1时，1也只出现一次
        3. num[i] > x,  0~999   当d>1时，1也只出现一次
    边界问题：
        i 在数字从后往前第一位
        枚举数字0的时候，前面几位 ！= 000 ，是 001~abc-1
计数问题
    for 遍历数字几（前缀和）
        计算从1 到n 中 x 出现的次数
        int count(int n, int x)
            数组存数字，低位在前，高位在后
            for 遍历位计算，从n-1数字高位/或者n-2等数字高位为0时开始，到 0 数字低位
                1、当xxx = 000~abc-1 且 当i位不是数字第一位的时候
                    比如n = 7， i = 3数字第四位 ， x ！= 0 求abc = get(gfedcba, 6，4)，然后 + abc * 1000
                    比如n = 7， i = 3数字第四位 ， x  == 0 求abc = get(gfedcba, 6，4)，然后 + abc * 1000 - 1000
                2、当xxx = abc 且  num[i] = x
                    比如n = 7， i = 3数字第四位 ，求efg = get(gfedcba, 2，0)，然后 + efg + 1
                3、当xxx = abc 且  num[i] > x
                    比如n = 7， i = 3数字第四位 ，求efg对应全部可能1000 = power10(3)，然后 + 1000 
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10;

//获得当前数 当前位 后面类efg的真值/前面类abc的真值  数组中，l后r前；数中，l大r小
int get(vector<int> num, int l, int r)
{
    int res = 0;
    for (int i = l; i >= r; i -- ) res = res * 10 + num[i];
    return res;// = abc 、efg
}

//求得当前数 当前位 是从后往前第几位 是数字从后往前第一位i=0---1、第二位i=1---10、第三位i=2---100、第四位i=3---1000
int power10(int x)
{
    int res = 1;
    while (x -- ) res *= 10;
    return res;
}

//计算从1 到n 的x出现的次数
int count(int n, int x)
{
    //如果 n = 0
    if (!n) return 0;

    //数组存数字，低位在前，高位在后
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();

    //遍历位计算，从n-1数字高位/或者n-2等数字高位为0时开始，到 0 数字低位
    //!x  0不可能出现在最高位，所以如果x == 0，那么i从n - 2开始循环，否则i从n - 1开始循环
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i -- )
    {
        //1、当xxx = 000~abc-1 且 当i位不是数字第一位的时候
            //比如n = 7， i = 3数字从前到后第四位 ， x ！= 0 求abc = get(gfedcba, 6，4)，然后 + abc * 1000
            //比如n = 7， i = 3数字从前到后第四位 ， x  == 0 求abc = get(gfedcba, 6，4)，然后 + abc * 1000 - 1000
        if (i < n - 1)
        {
            res += get(num, n - 1, i + 1) * power10(i);
            if (!x) res -= power10(i);//如果 遍历的是 0，前导不能是 000，删掉000对应的 后导乘积
        }
        //2、当xxx = abc 且  num[i] = x
            //比如n = 7， i = 3数字第四位 ，求efg = get(gfedcba, 2，0)，然后 + efg + 1
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        //3、当xxx = abc 且  num[i] > x
            //比如n = 7， i = 3数字第四位 ，求efg对应全部可能1000 = power10(3)，然后 + 1000 
        else if (num[i] > x) res += power10(i);
    }

    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b , a)
    {
        if (a > b) swap(a, b);

        for (int i = 0; i <= 9; i ++ )
            cout << count(b, i) - count(a - 1, i) << ' ';//前缀和
        cout << endl;
    }

    return 0;
}
