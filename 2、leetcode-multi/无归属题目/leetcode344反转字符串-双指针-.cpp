/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `s` 的形式给出。

不要给另外的数组分配额外的空间，你必须**[原地]修改输入数组**、使用 O(1) 的额外空间解决这一问题。
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }
};
  
    
swap可以有两种实现。
一种就是常见的交换数值：
int tmp = s[i];
s[i] = s[j];
s[j] = tmp;

一种就是通过位运算：
s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];