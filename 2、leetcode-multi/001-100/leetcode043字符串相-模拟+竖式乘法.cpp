/*
给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。

**示例 1:**

```
输入: num1 = "2", num2 = "3"
输出: "6"
```

**示例 2:**

```
输入: num1 = "123", num2 = "456"
输出: "56088"
```

**说明：**

1. `num1` 和 `num2` 的长度小于110。
2. `num1` 和 `num2` 只包含数字 `0-9`。
3. `num1` 和 `num2` 均不以零开头，除非是数字 0 本身。
4. **不能使用任何标准库的大数类型（比如 BigInteger）**或**直接将输入转换为整数来处理**。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        //逆序放入A、B中
        for (int i = n - 1; i >= 0; i -- ) A.push_back(num1[i] - '0');
        for (int i = m - 1; i >= 0; i -- ) B.push_back(num2[i] - '0');

        vector<int> C(n + m);//结果数组
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                C[i + j] += A[i] * B[j];//先忽略进位，求得每一位的值，这个值没有处理进位，从前到后依次是 个位、十位、百位
		
		//考虑进位
        for (int i = 0, t = 0; i < C.size(); i ++ ) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }

        //求出答案的 实际位数，去掉后面的0，越往后越是高位
        int k = C.size() - 1;
        while (k > 0 && !C[k]) k -- ;

        //转化为答案字符串，逆序转化为正序
        string res;
        while (k >= 0) res += C[k -- ] + '0';

        return res;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();

        string res(m + n + 1, '0');
        for (int j = 0; j < n; ++j){
            for (int i = 0; i < m; ++i){//边相乘边考虑进位
                int num = (res[i + j] - '0') + (num1[m - 1 - i] - '0') * (num2[n - 1 - j] - '0');
                res[i + j] = num % 10 + '0';//当前位
                res[i + j + 1] += num / 10; //下一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
		//去除首位'0'
        while (res.size() && res.back() == '0') res.pop_back();
        return res.empty() ? "0" : string(res.rbegin(), res.rend());
    }
};

