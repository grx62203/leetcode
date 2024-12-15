/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy;
        //a->next 是 m 的前一个节点
        for (int i = 0; i < m - 1; i ++ ) a = a->next;
        //b 是 m 节点，c是 m 节点 的下一个节点，是这个特殊段的前两个
        auto b = a->next, c = b->next;
        //移动左右对 n-m 次，结束的时候b、c是 n节点、n节点的下一个
        for (int i = 0; i < n - m; i ++ ) {
            auto t = c->next;//保留要断开位置的下一个节点
            c->next = b;     //断开右边连接左边
            b = c, c = t;    //刚连接好的一对左右后移 到 刚断开的一对左右
        }
        a->next->next = c;//将m节点        连接到 n节点的下一个
        a->next = b;      //将m节点的前一个 连接到 n节点
        return dummy->next;
    }
};
