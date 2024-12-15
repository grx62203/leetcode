/*
将一个给定字符串 `s` 根据给定的行数 `numRows` ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"PAYPALISHIRING"` 行数为 `3` 时，排列如下：

```
P   A   H   N
A P L S I I G
Y   I   R
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"PAHNAPLSIIGYIR"`。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```

**示例 1：**

```
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
```
*/


class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        //如果只有1行
        if (numRows == 1) return s;
        //按照行找元素，每一行地元素放在结果里面挨着
        for (int j = 0; j < numRows; j ++ )
        {
            //第一行和最后一行
            if (j == 0 || j == numRows - 1)
            { 
                for (int i = j; i < s.size(); i += (numRows-1) * 2)
                    res += s[i];
            }
            //中间行按照规律，每一个竖线和斜线算一组，走规律，每一行都连续两个两个地走规律添加
            else
            {
                for (int k = j, i = numRows * 2 - 1 - j - 1;
                        i < s.size() || k < s.size();
                        i += (numRows - 1) * 2, k += (numRows - 1) * 2)
                {
                    //将判断结束位置转换为单独的边界条件
                    if (k < s.size()) res += s[k];
                    if (i < s.size()) res += s[i];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
	    //将每一个竖线，按规律输出，当在中间行的时候，需要多输出一个字符
        //在中间行，要在最高点的基础上+， 第一列+i，第二列再+cycelen，第三列再+cycelen，
        //j的值是    0   cycelen  cycelen*2   递增   //同时也是每一列顶点的索引数
        //因此第一列与第二列之间的点，从第二列往会走i个点，因此  j + cycelen - i 代表从当前顶点往后走cycelen，然后往回走i
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) //代表存在斜线
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};