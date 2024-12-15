/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//4ms
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(-1), rh = new ListNode(-1);
        auto lt = lh, rt = rh;
        //结束的时候，lh是左边的左端的虚拟头节点 lt是左边的右端

        for (auto p = head; p; p = p->next) {
            if (p->val < x) lt = lt->next = p;
            else rt = rt->next = p;
        }

        lt->next = rh->next;//左边右端 的next = 右边左端
        rt->next = NULL;    //右边右端 的next = null
        
        return lh->next;
    }
};
