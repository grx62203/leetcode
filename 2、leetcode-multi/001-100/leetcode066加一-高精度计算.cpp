/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());//前面是低位，后面是高位
        int t = 1;
        for (auto& x: digits) {
            t += x;       //将进位加上
            x = t % 10;   //当前位去除进位
            t /= 10;      //得到新的高位进位
        }
        if (t) digits.push_back(t);           //最高位也要进位，则在数组的最后补上新的最高位

        reverse(digits.begin(), digits.end());//翻回来，前面高后面低

        return digits;
    }
};
