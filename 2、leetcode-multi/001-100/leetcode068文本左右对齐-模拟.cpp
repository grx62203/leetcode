/*
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0; i < words.size(); i ++ ) {
            int j = i + 1;
            int len = words[i].size();
            //贪心找到只放一个空格时，能连续放在当前行的所有单词
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth)
                len += 1 + words[j ++ ].size();

            string line;
            if (j == words.size() || j == i + 1) {  // 左对齐=最后一行+当前行只能放一个单词
                line += words[i];
                for (int k = i + 1; k < j; k ++ ) line += ' ' + words[k];
                //补齐后面一个空位置的空格
                while(line.size() < maxWidth) line += ' ';
            } else {                                // 左右对齐
                int cnt = j - i - 1, r = maxWidth - len + cnt;//中间必须有的的空位置、剩余的空格数量（一个空位置放若干空格）
                line += words[i];
                int k = 0;
                //左边的空格数量要多一个，直到空格数量 除以 空位置 的余数
                while (k < r % cnt) line += string(r / cnt + 1, ' ') + words[i + k + 1], k ++ ;
                while (k < cnt) line += string(r / cnt, ' ' ) + words[i + k + 1], k ++ ;
            }

            res.push_back(line);
            i = j - 1;//j是下一行第一个位置，i跳到下一行第一个位置，因为还有一个i++，所以需要i=j-1
        }

        return res;
    }
};
