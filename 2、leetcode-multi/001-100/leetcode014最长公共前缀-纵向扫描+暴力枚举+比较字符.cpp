/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

输入：strs = ["flower","flow","flight"]
输出："fl"

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` 仅由小写英文字母组成
*/

//数组越界时代码的运行结果是不确定的，和进程的执行环境有关。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;

        for (int i = 0;; i ++ ) {
            if (i >= strs[0].size()) return res;
            //超过第一个字符串，就代表不需要再找了
            char c = strs[0][i];
            //取出第一个字符串的第i个字符
            for (auto& str: strs)
                if (str.size() <= i || str[i] != c)
                    //依次判断其他字符串第i个字符是否一样
                    return res;
            	    //如果不相等返回上一次遍历的结果
            res += c;
            //遍历过一次i后，没有退出，代表第i个字符可以被添加到返回中
        }

        return res;
    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};