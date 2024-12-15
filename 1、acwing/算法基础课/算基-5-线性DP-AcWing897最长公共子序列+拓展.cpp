/*
给定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。

输入格式
第一行包含两个整数 N 和 M。

第二行包含一个长度为 N 的字符串，表示字符串 A。

第三行包含一个长度为 M 的字符串，表示字符串 B。

字符串均由小写字母构成。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N,M≤1000
*/
/*
0、DP
    状态表示 f[i][j]
        集合   
            所有 第一个序列的前i个字母、第二个序列的前j个字母 中的公共子序列 长度最大值
            条件 （数目限制、体积限制）
                 第一个序列的前i个字母
                 第二个序列的前j个字母
        属性   
            最大值
            (最小值)
            (数量)
    状态计算
        本质就是集合的划分
        f[i][j] = max(f[i - 1][j],  f[i][j - 1]);
        if (a[i] == b[j]) f[i][j] = max(f[i][j],      f[i - 1][j - 1] + 1);


1、f[i][j]有四种情况
00、 f[i - 1][j - 1]
01、 f[i - 1][j]
10、 f[i][j - 1]
11、 f[i - 1][j - 1] + 1
四项有重复值，01 与 10 与 11 都包括 00 这一项情况，所以先计算 01、10，再计算与 11 中 的 max
2、但是求数量的时候，集合的划分不能有重复
*/



#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);//将字符串索引 +1

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }

    printf("%d\n", f[n][m]);

    return 0;
}



//如果需要求最长公共子序列，则可以将f[i-1][i-1]存入临时变量，这样子就可以构成一维
//先求f[0][j],再求f[1][j]、、、、、、、、、、
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int l1 = s1.size(),l2 = s2.size();
        vector<string> res(l2+1,"");
        //i对应行
        for(int i=1;i<=l1;i++){
            string pre = "";
            //每一次循环都改变数组res
            for(int j=1;j<=l2;j++){
                string tem = res[j];//每次更改j对应的位置时，将其保存（i-1,j-1），以便j+1时用(i,j)
                if(s1[i-1] == s2[j-1]){
                    res[j] = pre+s1[i-1];
                }else{
                    res[j] = (res[j].size() > res[j-1].size() ? res[j] : res[j-1]);
                }
                pre = tem;
            }
        }
        
        if(res[l2] == "")
            return res[l2] = "-1";
        return res[l2];
    }
};
