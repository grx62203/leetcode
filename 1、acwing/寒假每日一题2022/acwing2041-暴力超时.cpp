/*
贝茜对她最近在农场周围造成的一切恶作剧感到抱歉，她同意帮助农夫约翰把一批新到的干草捆堆起来。

开始时，共有 N 个空干草堆，编号 1∼N。

约翰给贝茜下达了 K 个指令，每条指令的格式为 A B，这意味着贝茜要在 A..B 范围内的每个干草堆的顶部添加一个新的干草捆。

例如，如果贝茜收到指令 10 13，则她应在干草堆 10,11,12,13 中各添加一个干草捆。

在贝茜完成了所有指令后，约翰想知道 N 个干草堆的中值高度——也就是说，如果干草堆按照高度从小到大排列，位于中间的干草堆的高度。

方便起见，N 一定是奇数，所以中间堆是唯一的。

请帮助贝茜确定约翰问题的答案。

输入格式
第一行包含 N 和 K。

接下来 K 行，每行包含两个整数 A,B，用来描述一个指令。

输出格式
输出完成所有指令后，N 个干草堆的中值高度。
*/
/*
暴力解法-超时
用vector遍历范围存储高度
再倒叙vector，取得中位数
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> v(1000010);

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r ; )  v[i++]++;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int x = (n + 1) / 2 - 1;
	cout << v[x] << endl;
	return 0;
}