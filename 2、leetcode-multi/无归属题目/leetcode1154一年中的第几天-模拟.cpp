/*
给你一个字符串 `date` ，按 `YYYY-MM-DD` 格式表示一个 [现行公元纪年法](https://baike.baidu.com/item/公元/17855) 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。
*/
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));//去除字符串的字符，然后化作int 类型
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int amount[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            ++amount[1];//第二个月加 1 天
        }

        int ans = 0;
        for (int i = 0; i < month - 1; ++i) {
            ans += amount[i];//每超过一个月，就月份加上 这个月份的天数
        }
        return ans + day;
    }
};