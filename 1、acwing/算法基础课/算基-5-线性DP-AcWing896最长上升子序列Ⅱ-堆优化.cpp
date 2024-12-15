/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤100000，
−109≤数列中的数≤109
*/
//数据范围更大


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i)cin >> arr[i];

    vector<int>stk;//模拟堆栈
    stk.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (arr[i] > stk.back())//如果该元素大于栈顶元素,将该元素入栈
            stk.push_back(arr[i]);
        else//替换掉第一个大于或者等于这个数字的那个数
            *lower_bound(stk.begin(), stk.end(), arr[i]) = arr[i];
    }
    cout << stk.size() << endl;
    return 0;
}
/*
例 n: 7
arr : 3 1 2 1 8 5 6

stk : 3

1 比 3 小
stk : 1

2 比 1 大
stk : 1 2

1 比 2 小
stk : 1 2

8 比 2 大
stk : 1 2 8

5 比 8 小
stk : 1 2 5

6 比 5 大
stk : 1 2 5 6

stk 的长度就是最长递增子序列的长度

*/
