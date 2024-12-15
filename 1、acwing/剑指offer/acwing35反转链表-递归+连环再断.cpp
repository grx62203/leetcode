/*
定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

思考题：

请同时实现迭代版本和递归版本。
数据范围
链表长度 [0,30]。
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tail = reverseList(head->next);
        //每一次递归，都是先连环再断线，也就是反转，直到最后一次递归，也就是
        head->next->next = head;//后驱的新后驱指向后驱的前驱
        head->next = nullptr;   //后驱不再是后驱
        return tail;
    }
};
