/*
在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留。

数据范围
链表中节点 val 值取值范围 [0,100]。
链表长度 [0,100]。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            auto q = p->next->next;
            //从当前节点（p->next）开始找重复段，直到q的前一个
            while (q && q->val == p->next->val) q = q->next;
            //如果q的下一个还是q的下一个，往后走一步
            if (p->next->next == q) p = p->next;
            //如果有重复段，直接更新当前节点位（p->next）被重复段的后一个所替换
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
