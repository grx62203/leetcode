/*
给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数 n。

第二行包含 n 个整数（均在 0∼105范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

数据范围
1≤n≤105
*/

/*
双指针-滑动窗口
滑动窗口例子
i在前面跑，j在后面跑，形成一个窗口
1、每次i向前走的时候，扩大窗口,然后记录 i 指向元素的 计数
2、当j在i后面，且有重复元素的时候，j指向元素的计数 -1.且j向前走一步，缩小窗口，此时得到一个新的最大长度
3、求取此时i 对应的后面窗口长度与 记录最大长度的 max
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    int res = 0;
    //1、每次i向前走的时候，扩大窗口
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[q[i]] ++ ;//记录 i 指向元素的 计数
        //2、当j在i后面，且有重复元素的时候，j指向元素的计数 -1.且j向前走一步
        while (j < i && s[q[i]] > 1) s[q[j ++ ]] -- ;
        //3、求取此时i 对应的后面窗口长度与 记录最大长度的 max
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
