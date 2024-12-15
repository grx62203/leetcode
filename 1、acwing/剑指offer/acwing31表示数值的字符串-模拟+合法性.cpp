/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。

但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

注意:
	小数可以没有整数部分，例如.123等于0.123；
	小数点后面可以没有数字，例如233.等于233.0；
	小数点前面和后面可以有数字，例如233.666;
	当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
	当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4;
数据范围
	输入字符串长度 [0,25]。
	字符串中不含空格。
*/
class Solution {
public:
    bool isNumber(string s) {
    	//1、去掉前后空格的新s，判合法
    	if( !s.empty() )
        {
        	s.erase(0,s.find_first_not_of(" "));
        	s.erase(s.find_last_not_of(" ") + 1);
        }
        int i = 0, j = s.size() - 1;
        //while (i < s.size() && s[i] == ' ') i ++ ;
        //while (j >= 0 && s[j] == ' ') j -- ;
        if (i > j) return false;
        s = s.substr(i, j - i + 1);
        //2、去掉可能的合法正负号，判合法
        if (s[0] == '-' || s[0] == '+') s = s.substr(1);
        if (s.empty() || s[0] == '.' && s.size() == 1) return false;
        //3、从第一个合法字符开始，可能是“.”，也可能是数字
        int dot = 0, e = 0;//记录点和e的数量
        for (int i = 0; i < s.size(); i ++ )
        {
            if (s[i] >= '0' && s[i] <= '9');
            else if (s[i] == '.')
            {
                dot ++ ;
                //e后面出现点、多个点，非法
                if (e || dot > 1) return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                e ++ ;
                //e是最后一个、第一个、多个e、点e相连，都非法
                if (i + 1 == s.size() || !i || e > 1 || i == 1 && s[0] == '.') return false;
                //正负号除了第一位只能在e后出现，但正负号之后必须有且是数字，否则非法
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if (i + 2 == s.size()) return false;
                    i ++ ;//跳过后面的正负号
                }
            }
            //如果当前是正负号、其他字符，非法
            else return false;
        }
        return true;
    }
};
