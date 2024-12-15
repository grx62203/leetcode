/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

输入：head = [1,2,3,4]
输出：[2,1,4,3]

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`
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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p->next && p->next->next;) {
            auto a = p->next, b = a->next;
            //p是0、a是1、b是2、b->next是3，先备份12，中间一对变换位置，则先连接前再连接后再连接中
			p->next = b;           //0指向了2
			a->next = b->next;     //1指向了3
			b->next = a;           //2指向了1
			p = a;                 //把p指向了原来的1，此时原来的1234变成立2134，然后就操作1345，p指向1，然后交换的是34
        }

        return dummy->next;
    }
};