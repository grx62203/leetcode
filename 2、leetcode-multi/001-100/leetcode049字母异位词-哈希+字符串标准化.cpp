/*
给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。
**字母异位词** 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

**示例 1:**
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

- `1 <= strs.length <= 104`
- `0 <= strs[i].length <= 100`
- `strs[i]` 仅包含小写字母
*/

//哈希表的 key是sort的结果，value是原字符串

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& str: strs) {
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(str);//nstr 和 str 是不一样的，nstr是将字符串标准化的结果，作为key去统计
            //[key].push_back(move(str));更好
        }

        vector<vector<string>> res;
        for (auto& item : hash) res.push_back(item.second);//每一次 push_back 都是添加一类相似的，也就是hash 的每个内容里面是一类相似的
        //auto可以换成普通for循环
        //for (auto i = dict.begin(); i != dict.end(); i ++ )   res.push_back(move(i -> second));
        
        return res;
    }
};