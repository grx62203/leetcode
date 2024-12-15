/*
给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "10"
输出: "101"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/JFETK5
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//leetcode
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());//改成前面低位后面高位
        reverse(b.begin(), b.end());//改成前面低位后面高位

        string c;
        for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ ) {
            if (i < a.size()) t += a[i] - '0';
            if (i < b.size()) t += b[i] - '0';
            c += to_string(t % 2);//保留当前位
            t /= 2;               //得到进位
        }

        reverse(c.begin(), c.end());//改回来，前面高位后面低位
        return c;
    }
};

//leetcode
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry != 0) {
            int digitA = i >= 0 ? a[i] - '0' : 0;
            int digitB = j >= 0 ? b[j] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum >= 2 ? 1 : 0;
            sum = sum >= 2 ? sum - 2 : sum;
            res += to_string(sum);
            i --;
            j --;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//leetcode
class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length()-1,bl = b.length()-1;
        int len,carry=0;  //len：表示result的下标，carry：为1时表示向前进位，为0表示不进位
        string result;    //作为输出结果进行输出
        len = al>=bl ? al:bl;
        result = len==al? a:b;

        while(al>=0 || bl>=0)
        {
            int digitA= al>=0?a[al--]-'0':0;    //需要加上限制al>=0和bl>=0，
            int digitB= bl>=0?b[bl--]-'0':0;    //
            switch(digitA+digitB+carry)
            {
                case 0:  carry=0;   break;
                case 1: result[len] = '1';   carry=0;  break;
                case 2: result[len] = '0';   carry=1;  break;
                case 3: result[len] = '1';   carry=1;  break;
                default:  break;
            }
            if(len>0){len--;}
        }
        
        if(carry==1){result.insert(0,"1");}  //insert第二个参数非要是字符串，要用双引号，单引号时会报错
        return result;
    }
};