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
/*
反转一部分一部分来
保存b
将反转序列后面的一个个 a直接链接c，将b插入序列头部

x----a-b-c
1、将b节点拿出来
2、将a节点与c节点相连
3、将b与序列头部节点相连
4、将x节点与b相连
x-b----a-c
*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;       //1、将b节点拿出来
            cur->next = next->next; //2、将a节点与c节点相连
            next->next = pre->next; //3、将b与序列头部节点相连
            pre->next = next;       //4、将x节点与b相连
        }
        return dummyNode->next;
    }
};
