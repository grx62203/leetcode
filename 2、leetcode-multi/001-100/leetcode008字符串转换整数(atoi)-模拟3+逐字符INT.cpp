/*
请你来实现一个 `myAtoi(string s)` 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 `atoi` 函数）。

函数 `myAtoi(string s)` 的算法如下：

- 读入字符串并丢弃无用的前导空格
- 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
- 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
- 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 `0` 。必要时更改符号（从步骤 2 开始）。
- 如果整数数超过 32 位有符号整数范围 `[−231, 231 − 1]` ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 `−231` 的整数应该被固定为 `−231` ，大于 `231 − 1` 的整数应该被固定为 `231 − 1` 。
- 返回整数作为最终结果。

**注意：**

- 本题中的空白字符只包括空格字符 `' '` 。
- 除前导空格或数字后的其余字符串外，**请勿忽略** 任何其他字符。

输入：s = "4193 with words"
输出：4193
解释：
第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
         ^
第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         ^
第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
             ^
解析得到整数 4193 。
由于 "4193" 在范围 [-231, 231 - 1] 内，最终结果为 4193 。

**提示：**

- `0 <= s.length <= 200`
- `s` 由英文字母（大写和小写）、数字（`0-9`）、`' '`、`'+'`、`'-'` 和 `'.'` 组成
*/


//leetcode
class Solution {
public:
    int strToInt(string str) {
        bool sign = true;   //默认为正数
        //先舍弃开头可能存在的空格
        int i = 0;
        while(i < str.size() && str[i] == ' ') i++;
        //接着判断首个字符是否为正负号
        if(str[i] == '-') {
            sign = false;  //该字符串片段为负数
            i++;          //移至下一个字符接着判断
        }
        else if(str[i] == '+') i++;   //如果首个字符为‘+’则sign已经默认为true而无须更改，直接移动到下一位即可
        //下面开始对非正负符号位进行判断
        if(str[i] < '0' || str[i] > '9') return 0;  //如果第一个正负号字符后的首个字符就不是数字字符(也可能第一个字符就不是正负号)，那么直接返回0
        int res = 0;   //这里res用的int型，需要更加仔细考虑边界情况，但如果用long的话可以省去一些麻烦
        int num;      //用来单独存储单个字符转换而成的数字
        int border = INT_MAX / 10;  //用来验证计算结果是否溢出int范围的数据
        while(i < str.size()){
            if(str[i] < '0' || str[i] > '9') break;  //遇到非数字字符则返回已经计算的res结果
            if(res > border || res == border && str[i] > '7')  
            	//注意这句话要放在字符转换前，因为需要验证的位数比实际值的位数要少一位
				//这里比较巧妙的地方在于 1. 用低于int型数据长度一位的数据border判断了超过int型数据长度的值 2. 将超过最大值和低于最小值的情况都包括了
            	return sign == true ? INT_MAX : INT_MIN;
            //开始对数字字符进行转换
            num = str[i] - '0';
            res = res * 10 + num;
            i++;
        }
        //最后结果根据符号添加正负号
        return sign == true ? res : -res;
    }
};