/*
使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

*/
/*
DP O(n^4)
状态表示：f[i, j, k]
	1.1 集合：s1[i , i + k - 1]与s2[j, j + k - 1]所有匹配方案的集合
	1.2 属性：集合是否非空
状态计算
	将f[i, j, k]表示的集合按s1第一段的长度划分划分成k - 1类。
	设s1第一段的长度为u。则s1[i ~ i + k - 1]与s2[j, j + k - 1]有两种匹配方案，分别判断即可：
	k分为u和k-u两部分
		(1) f[i][j][u] && f[i + u][j + u][k - u]-----------------------i~i+u 与 j~j+u    匹配长度u      且   i+u~i+k 与 j+u~j+k匹配长度k-u
		(2) f[i][j + k - u][u] && f[i + u][j][k - u]-------------------i~i+u 与 j+k-u~j+k匹配长度u      且   i+u~i+k 与 j~j+k-u匹配长度k-u
时间复杂度分析：状态数 O(n^3)，状态转移计算量为 O(n)，所以总时间复杂度为 O(n^4)

两个串某一相同段的匹配性 
	如果任意长度分两段
		(a前与b前匹配 且 a后与b后匹配)  或者   (a前与b后匹配 且 a后与b前匹配)
匹配的两段长度相等
*/
/*
遍历长度
	遍历s1的起始位置
		遍历s2的起始位置
			如果长度 ==1
			如果长度！=1
				遍历当前长度时候的不同分割情况
					if (f[i][j][u] && f[i + u][j + u][k - u] || f[i][j + k - u][u] && f[i + u][j][k - u])   f[i][j][k] = true;
*/
//40ms


class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        //遍历 s1 的长度可能性，当k=n的时候，s1长度完整了，s2长度完整的时候，求f[0][0][n]
        for (int k = 1; k <= n; k ++ )
        	//遍历s1的起始位置，为了求取后一半，其实i遍历到 n-k位置就可以了，但是为了求k=n的时候，可以进入循环
            for (int i = 0; i + k - 1 < n; i ++ )
            	//遍历s2的起始位置
                for (int j = 0; j + k - 1 < n; j ++ ) {
                    if (k == 1) {//特例
                        if (s1[i] == s2[j]) f[i][j][k] = true;
                    } else {//再将递增的前半段长度分割成 u 与 k-u两段，研究这两段的可能匹配性得到当前k长度的匹配可能性
                        for (int u = 1; u < k; u ++ ) {
                        	//每一个i、j都不用前边i、j的数据，但是每一个 k，都要用前面 k 的数据，所以就要求k小的时候对应的i、j也足够多
                        	//最多可以用到前面k对应的 i+u=i+k-1，与此同时k最大会计算到 n-1，所以循环中i、j要一直循环到 i+n-1-1，也就是i+k-1<n
                            if (f[i][j][u] && f[i + u][j + u][k - u] || f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
        return f[0][0][n];
    }
};
