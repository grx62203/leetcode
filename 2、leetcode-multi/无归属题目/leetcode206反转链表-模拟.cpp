/*
给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return NULL;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        auto a = p->next,b = a->next;
        while(b)
        {
            auto c = b -> next;
            b->next = a;
            a = b, b = c;
        }
        auto c = p -> next;
        p->next = a;
        c->next = nullptr;
        return dummy->next;
    }
};