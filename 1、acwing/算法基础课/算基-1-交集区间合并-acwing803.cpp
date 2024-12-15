/*
给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 l 和 r。

输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围
1≤n≤100000
−109≤li≤ri≤109
*/

/*
交集区间合并
将有交集的区间进行合并，返回新的数组个数
1、按照区间左端点排序
2、扫描，合并所以有交集的区间（留下并集）
	维护当前区间,累计区间个数
		下一个区间在当前区间之内-删掉下一个区间
		下一个区间与当前区间有交集 - 更新当前区间的first 与下一个区间的end，更新为并集
		下一个区间与当前区间没有交集 - 无操作

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;//存储左右区间

void merge(vector<PII> &segs)
{
    vector<PII> res;
    //2、按照区间的左端点进行排序
    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;//对维护的区间初始化，维护的区间一直存在，只是一直在剖离 并集
    //3、遍历每一个区间来与维护的区间进行比较，得到新的并集 
    for (auto seg : segs)
    	//4、第一个区间不加入答案（除非只有一个区间），作为新的被维护的区间
    	//5、如果新的区间 与 被维护区间没有交集（被维护的ed < 新的st），将被维护的区间加入答案，更新 新的区间为被维护的区间
    	//6、如果新的区间 与 被维护区间有 交集， 更新 被维护的区间 的 ed 为有交集的两个区间的较大 ed，此时包含了两种情况，合并一起处理
    	//7、直到被维护的区间 与 新的区间 没有交集，那么当前被维护的区间使命结束
    	//8、遍历完 区间后，将此时维护的区间加入答案，为最后一个新区间
        if (ed < seg.first)//没有交集，便需要隔离开 被维护区间 与 新区间
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);//有交集，就需要找到两个区间的并集

    if (st != -2e9) res.push_back({st, ed});//将最后一个 此时的  被维护区间加入答案

    segs = res;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        //1、读入左右区间
        segs.push_back({l, r});
    }

    merge(segs);//合并区间

    cout << segs.size() << endl;

    return 0;
}