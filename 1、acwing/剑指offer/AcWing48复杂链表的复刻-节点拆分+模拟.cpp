/*
请实现一个函数可以复制一个复杂链表。

在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null。

注意：

函数结束后原链表要与输入时保持一致。
数据范围
链表长度 [0,500]。
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
    	//1-2-3-4-5
    	//1-1-2-2-3-3-4-4-5-5
        for (auto p = head; p;)
        {
            auto np = new ListNode(p->val);//新的节点，与p值一样
            auto next = p->next;           //保存旧链表中p的next
            p->next = np;                  //更新p的next为新的节点
            np->next = next;               //更新新的节点的next为旧链表中p的next
            p = next;                      //将p这个代称更新旧链表下一个
        }
        //将旧链表的每一个随机指向，在对应新链表中找到对应的随机指向，这个指向是节点*
        for (auto p = head; p; p = p->next->next)
        {
            if (p->random)
                p->next->random = p->random->next;
        }
        //虚拟头节点
        auto dummy = new ListNode(-1);
        auto cur = dummy;//节点指针等于，就是指向同一个地址了
        for (auto p = head; p; p = p->next)
        {
            cur->next = p->next;    //跳过旧链表的奇数位置，直接等于偶数位置
            cur = cur->next;        //cur跳到下一个偶数位置
            p->next = p->next->next;//p跳到下一个奇数位置（旧）
        }
        //先逐个复制节点，再逐个复制随机指向，利用虚拟头节点跳跃连接新链表偶数节点
        return dummy->next;
    }
};
