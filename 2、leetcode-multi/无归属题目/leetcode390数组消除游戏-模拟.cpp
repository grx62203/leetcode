/*
模拟-数组消除游戏
列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：
从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
给你整数 n ，返回 arr 最后剩下的数字。
*/
class Solution {
public:
    int lastRemaining(int n) {
        int remain = n;
        bool flag= true;//记录此时正在正向删还是反向，一开始是正方向
        int res=1;维护第一个元素的值
        int step= 1;这是记录的变化量
        while(remain>1){
            if(flag||remain%2==1){//当正向或者反向时数组元素个数为奇数时，需要更新维护的第一个元素的值
                res+=step;
            }
            flag=!flag;//更改方向
            step*=2;//根据找出的规律，每次为原来的两倍。
            remain/=2;//每删除一趟，剩余的元素个数为原来的一半，当剩余元素为1时，退出循环。
        }
        return res;
    }
};
