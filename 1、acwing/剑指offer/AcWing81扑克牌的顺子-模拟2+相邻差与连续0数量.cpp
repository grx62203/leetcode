/*
从扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。

2∼10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，大小王可以看做任意数字。

为了方便，大小王均以 0 来表示，并且假设这副牌中大小王均有两张。

样例1
输入：[8,9,10,11,12]

输出：true
样例2
输入：[0,8,9,11,12]

输出：true
*/


/*
能组成顺子需要满足的两个条件是：
	除了0以外不能出现两个相同的数字；
	排序后两个相邻数字的差值不能大于0的个数。
按照这两个条件进行判断即可。
这个题解没办法判断循环的顺子 [1, 10, 11, 12, 13]
*/
class Solution {
public:
    bool isContinuous( vector<int> numbers ) {
        if(numbers.size()!=5)
            return false;
        sort(numbers.begin(), numbers.end());
        int zerocnt = 0;
        for(int i = 0;i<4;i++){
            if(numbers[i]==0)
                zerocnt += 1;
            else{
                if(numbers[i+1]-numbers[i]-1>zerocnt)//相邻数字间隔大于0的个数
                    return false;
                if(numbers[i+1]==numbers[i])//有对子
                    return false;
                zerocnt -= numbers[i+1] - numbers[i]-1;
            }
        }
        return true;
    }
};



//leetcode
class Solution {
    public boolean isStraight(int[] nums) {
        int joker = 0;
        Arrays.sort(nums); // 数组排序
        for(int i = 0; i < 4; i++) {
            if(nums[i] == 0) joker++; // 统计大小王数量
            else if(nums[i] == nums[i + 1]) return false; // 若有重复，提前返回 false
        }
        return nums[4] - nums[joker] < 5; // 最大牌 - 最小牌 < 5 则可构成顺子
    }
};