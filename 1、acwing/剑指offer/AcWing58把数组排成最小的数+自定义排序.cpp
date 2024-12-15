/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

例如输入数组 [3,32,321]，则打印出这 3 个数字能排成的最小数字 321323。

数据范围
数组长度 [0,500]。

样例
输入：[3, 32, 321]

输出：321323
注意：输出数字的格式为字符串。
*/
//因为它是所有对象共有的功能，定义成静态，就不用那些对象来调用
//这样只是说明了用静态函数会更好，而没有说明为啥不能用非静态函数。这种设计感觉更像是Cpp作者拍脑袋定的。
//非静态成员函数都有一个默认的this指针参数的, 所以相当于cmp有三个参数了, 那就不行了. 而静态成员函数没有这个this指针, 就ok了

class Solution {
public:

    static bool cmp(string a, string b)
    {
        return a + b < b + a;
    }
    string printMinNumber(vector<int>& nums) {
        vector<string> num_strs;
        for (auto num : nums) num_strs.push_back(to_string(num));
        sort(num_strs.begin(), num_strs.end(), cmp);
        string res;
        for (auto num : num_strs) res += num;
        return res;
    }
};

//
class Solution {
public:
    static bool myCmp(int &a, int &b) {
        if (to_string(a) + to_string(b) < to_string(b) + to_string(a))
        return true;
        else return false;
    }
    string printMinNumber(vector<int>& nums) {
        string str;
        if(!nums.size()) return str;
        sort(nums.begin(), nums.end(), myCmp);
        for(int i = 0 ; i < nums.size(); i ++ ) {
            str += to_string(nums[i]);
        }
    return str;    
    }
};

//leetcode
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};

//
class Solution {
public:
    string printMinNumber(vector<int>& nums) {
        vector<string> res(nums.size());
        for(int i = 0; i < nums.size(); ++i) //直接转化为string数组进行操作
            res[i] = to_string(nums[i]);
        sort(res.begin(), res.end(), [](string a, string b)->bool{return a + b < b + a;}); //lamda表达式
        string ans;
        for(auto x : res) ans += x;
        return ans;
    }
};
