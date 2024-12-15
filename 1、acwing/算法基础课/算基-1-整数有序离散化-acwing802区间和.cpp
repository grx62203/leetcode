/*
假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。

现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。

接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r]之间的所有数的和。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含两个整数 x 和 c。

再接下来 m 行，每行包含两个整数 l 和 r。

输出格式
共 m 行，每行输出一个询问中所求的区间内数字和。

数据范围
−109≤x≤109
1≤n,m≤105
−109≤l≤r≤109
−10000≤c≤10000
*/

/*
整数有序离散化
求取某个区间和（数据比较少的时候可以直接前缀和）
1、把所求区间内 用过的数 拿过来排序映射到一个从1 开始的顺序数组上
2、再用前缀和的方式解决区间和
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];//a 是数 、 s 是和

vector<int> alls;
vector<PII> add, query;//改变某个值的操作、求取区间和的操作

//利用整数二分找到第一个大于等于 x 的位置
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;//映射到 1、2、3、、、、n
}

int main()
{
    cin >> n >> m;
    //1、读入增加操作
    for (int i = 0; i < n; i ++ )
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        //2、将所有使用过的数 加入 待离散化数组里
        alls.push_back(x);
    }
    //3、读入左右区间
    for (int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        //4、将左右区间加入到 待离散化数组里
        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    //5、将离散化数组排序去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理插入
    //6、对于增加操作，实现 原空白数组a 中的某个值的对应映射 增加（左位坐标、右位增值）
    for (auto item : add)
    {
        int x = find(item.first);//找到离散化后的对应映射坐标，从1 开始
        a[x] += item.second;
    }

    // 预处理前缀和
    //7、预处理前缀和，用add->second 来求取区间和、因为映射+1，所以这里i<=size
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto item : query)
    {
        //8、找到所求区间 对应的 离散化后坐标，求和
        int l = find(item.first), r = find(item.second);
        //9、虽然离散后的l、r是闭区间，包括了询问坐标，但是询问坐标没有求前缀和，所以不会计算
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}