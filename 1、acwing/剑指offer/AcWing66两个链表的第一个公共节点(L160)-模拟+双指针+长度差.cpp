/*
输入两个链表，找出它们的第一个公共结点。

当不存在公共节点时，返回空节点。

数据范围
链表长度 [1,2000]。

样例
给出两个链表如下所示：
A：        a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

输出第一个公共节点c1
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这种方法不能有环
//先计算出两个链表的长度，可以让比较长的先走两个链表长度之差的步数，两个再一起走。
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        int la = 0, lb = 0;
        for (auto t = headA; t; t = t->next) la ++;
        for (auto t = headB; t; t = t->next) lb ++;
        int k = la - lb;
        if (la < lb) {
            p = headB, q = headA;
            k = lb - la;
        }
        while(k --) {
            p = p->next;
        }
        while(p) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};
