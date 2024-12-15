/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//重复元素不保留
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            auto q = p->next->next;
            //从当前节点（p->next）开始找重复段，直到q成为第一个不相等的
            while (q && q->val == p->next->val) q = q->next;
            //如果q还是p的下一个的下一个，那么说明q的下一个没有重复，则p往后走一步
            if (p->next->next == q) p = p->next;
            //如果有重复段，直接删掉p的下一个开始的到q的前一个，也就是p指向q
            else p->next = q;
        }
        /*
        head = dummy->next;
        delete dummy;
        return head;
        */
        return dummy->next;
    }
};
