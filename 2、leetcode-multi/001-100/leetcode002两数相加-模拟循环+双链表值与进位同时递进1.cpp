/*
给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

输入：l1 = [0], l2 = [0]
输出：[0]
*/

/*
在实现中需要注意的有：

1. 不可以把链表先转化成 int 型数字再求和，因为**可能溢出**；
2. 两个「**加数**」的字符串长度可能不同；
3. 在最后，如果进位 `carry` 不为 0，那么**最后需要计算进位**；
*/

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        auto dummy = new ListNode(-1)；cur = dummy;//虚拟头节点，调用不到
        //ps1
        //ListNode *res = new ListNode(-1);   //添加虚拟头结点，简化边界情况的判断，避免判断是不是第一个点 
        //ListNode *cur = res; 
        int i = 0;
        while(l1 || l2 || t){                //代表l1没有循环完、或者l2没有循环完、进位不为0
            if(l1) t += l1->val,l1 = l1->next;
            if(l2) t += l2->val,l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);
            t/=10;   
        }
        return dummy->next;                  //虚拟头节点的next指针就是真正的链表头节点
    }
}；