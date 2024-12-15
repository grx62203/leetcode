/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

*/

class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }
    //u表示枚举到的字符串下标，k表示当前截断的IP个数，s表示原字符串
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();//最后会多一个 "."，需要弹出
                ans.push_back(path);
            }
            return;
        }
        if (k == 4) return;//提前四段了，无效
        for (int i = u, t = 0; i < s.size(); i ++ ) {
            if (i > u && s[u] == '0') break;  // 新的截断字符大于1个 且 新的截断第一个字符是0 == 有前导0则break
            t = t * 10 + s[i] - '0';          // 累计前面到现在的和，如果累计数目多了，会超过255break的
            if (t <= 255) dfs(s, i + 1, k + 1, path + to_string(t) + '.');//变参数=不需要回溯
            else break;
        }
    }
};
