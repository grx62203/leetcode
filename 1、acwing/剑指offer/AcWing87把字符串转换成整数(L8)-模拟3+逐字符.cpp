/*
请你写一个函数 StrToInt，实现把字符串转换成整数这个功能。

当然，不能使用 atoi 或者其他类似的库函数。

数据范围
输入字符串长度 [0,20]。

样例
输入："123"

输出：123
注意:

你的函数应满足下列条件：

忽略所有行首空格，找到第一个非空格字符，可以是 ‘+/−’ 表示是正数或者负数，紧随其后找到最长的一串连续数字，将其解析成一个整数；
整数后可能有任意非数字字符，请将其忽略；
如果整数长度为 0，则返回 0；
如果整数大于 INT_MAX(231−1)，请返回 INT_MAX；如果整数小于INT_MIN(−231) ，请返回 INT_MIN；
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