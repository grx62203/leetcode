/*
给你两个字符串 `s` 和 `goal` ，只要我们可以通过交换 `s` 中的两个字母得到与 `goal` 相等的结果，就返回 `true` ；否则返回 `false` 。

交换字母的定义是：取两个下标 `i` 和 `j` （下标从 `0` 开始）且满足 `i != j` ，接着交换 `s[i]` 和 `s[j]` 处的字符。

- 例如，在 `"abcd"` 中交换下标 `0` 和下标 `2` 的元素可以生成 `"cbad"` 。
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() == 0 && goal.length() == 0 ) return true;
        if(s.length() != goal.length()) return false;
        int a = 0;
        vector<int> v;
        unordered_multimap<char, int> map;
        for(int i = 0; i< s.length(); ++i){
            if(s[i]!= goal[i]){
                v.push_back(i);
                a++;//不相等字符的数量
            }
            map.insert({s[i], i});
        }
        
        if(a == 2){
            int b = v[0],c = v[1];
            if(s[b]== goal[c] && s[c] == goal[b]) return true; 
        }
        else if ( a==0){
            for(int i= 0; i < s.length(); ++i){
                if(map.count(s[i]) > 1) return true;
            }
        }
        return false;

    }
};