/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

假设字符串中只包含从 a 到 z 的字符。

数据范围
输入字符串长度 [0,1000]。

样例
输入："abcabc"

输出：3
*/
//因为我们可以很明显的看出，当前字符加入的时候，他的状态可以由两种状态来设定，
//第一是从f[i-1]转移，但是由于s[i]可能出现了不止一次，
//所以其实需要将f[i-1]和s[j]最近两次出现的区间长度做比较，选择最短的那个作为f[i]的状态。
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int n = s.size();
        if(n <=1 ) return n;
        vector<int> f(n,0);
        f[0] = 1;
        int arr[256]{0};
        for( int i = 1; i < 256; i ++ ) arr[i] = -1;
        arr[s[0]] = 0;
        int res = 0;
        //遍历s[1]~[n-1]
        for( int i = 1; i < n; i ++ )
        {
        	//如果当前字符没有出现过
            if(arr[s[i]] == -1) {
                arr[s[i]] = i;//更新s[i]出现的位置
                f[i] = f[i - 1] + 1;
                if(res < f[i]) res = f[i];
                //cout << f[i] << endl;
            //如果当前字符出现过
            }else{
            	//min（假设s[i]上一次出现在f[i-1]范围之外， 之内），哪个更小，则代表哪个为真
                f[i] = min(f[i - 1] + 1, i - arr[s[i]]);
                arr[s[i]] = i;//更新s[i]出现的位置
                if(res < f[i]) res = f[i];
                //cout << f[i] << endl;
            }
        }
        return res;
    }
};