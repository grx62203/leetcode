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
//不同部分为a， 和b，公共部分为c；a + c + b = b + c + a;让两个一起走，a走到头就转向b， b走到头转向a，则在公共部分相遇
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA, p2 = headB;
        while (p1 != p2)
        {
            if (p1) p1 = p1->next;
            else p1 = headB;
            if (p2) p2 = p2->next;
            else p2 = headA;
        }
        return p1;
    }
};