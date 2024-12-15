/*
给你一个字符串 `s` ，其中包含字母顺序打乱的用英文单词表示的若干数字（`0-9`）。按 **升序** 返回原始的数字。
*/
class Solution {
public:
    string originalDigits(string s) {
        string name[] = {
            "zero", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"
        };
        int ord[] = {0, 8, 3, 2, 6, 4, 5, 1, 7, 9};
        //这个顺序保证每次都可以找到对应的
        //从z对应0开始
        unordered_map<char, int> cnt;
        for (auto c: s) cnt[c] ++ ;
        //统计每个字母出现的次数
        string res;
        for (int x: ord) {
        //按顺序枚举每个单词
            while (true) {
            //x不一定有一个，需要一个while循环，不停找x，找完为止，结束条件就是break
                bool flag = true;
                //表示x得每个字母是不是都有
                for (auto c: name[x])
                //罗列每个单词的字母，然后用map判断有没有这个字母，有就删掉，没有就break
                    if (!cnt[c]) {
                    //如果x得某个字母没有，改变标签
                        flag = false;
                        break;
                    }
                if (flag) {
                //说明当前单词的每个字母都 存在
                    res += to_string(x);
                    //将x加入答案中
                    for (auto c: name[x]) cnt[c] -- ;
                    //找到当前单词的每个字母，索引-1
                }
                else break;
            }
        }
        sort(res.begin(), res.end());
        //对res中得数字进行排序，从小到大
        return res;
    }
};
