/*
给定一个字符串 `s` 和一些 **长度相同** 的单词 `words` **。**找出 `s` 中恰好可以由 `words` 中所有单词串联形成的子串的起始位置。

注意子串要与 `words` 中的单词完全匹配，**中间不能有其他字符** ，但不需要考虑 `words` 中单词串联的顺序。

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。

- `1 <= s.length <= 104`
- `s` 由小写英文字母组成
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `words[i]` 由小写英文字母组成
*/

//起始位置分成w组
//cnt维护有多少个单词时给定集合的，有效的
//wd[word] 如果是有效单词，会增加，tol值大于0，但是如果是无效单词，增加后大于tol值=0，移动后等于tol=0，所以不影响判别 


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;                 //防止溢出，边界条件
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot;
        for (auto& word : words) tot[word] ++ ;        //枚举单词，存储单词出现的次数

        for (int i = 0; i < w; i ++ )                  //分为w组，每组分别滑动窗口
        {
            unordered_map<string, int> wd;
            //窗口  长度是 m*w
            int cnt = 0;
            for (int j = i; j + w <= n; j += w) {
            	//维护窗口左端
                if (j >= i + m * w)                   //窗口大小超限之后每一次都要删掉一个单词
                {
                    auto word = s.substr(j - m * w, w);//找到前面的单词
                    wd[word] -- ;                      //删掉
                    //无效单词会大于等于
                    if (wd[word] < tot[word]) cnt -- ; //如果删掉了有效单词，cnt减去1
                }
                auto word = s.substr(j, w);            //找到下一个单词
                wd[word] ++ ;                          //把下一个单词加进去
                //无效单词这里会大于
                if (wd[word] <= tot[word]) cnt ++ ;    //加进去之后判别是否有效，用cnt标记增长
                if (cnt == m) res.push_back(j - (m - 1) * w);//有效标记达标，输出其实位置
            }
        }

        return res;
    }
};