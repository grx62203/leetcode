/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/
//8ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode *tail;
        for(auto p = head ; p ; p = p->next){
            tail = p;
            n++;
        }
        k %= n;
        if(!k) return head;//如果k是0，或者n的倍数，就还是返回head

        auto p = head;
        for( int i = 0; i < n-k-1; i++) p = p->next;//此时p的后面有k个节点
        tail->next = head;                          //连环
        head = p->next;                             //
        p->next = nullptr;                           //p的后面的k个节点跑到了最前面
        return head;

    }
};