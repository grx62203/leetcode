/*
将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

- 两个链表的节点数目范围是 `[0, 50]`
- `-100 <= Node.val <= 100`
- `l1` 和 `l2` 均按 **非递减顺序** 排列
*/


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
/*
新建头部的保护结点 dummy，设置 cur 指针指向 dummy。
若当前 l1 指针指向的结点的值 val 比 l2 指针指向的结点的值 val 小，则令 cur 的 next 指针指向 l1，且 l1 后移；否则指向 l2，且 l2 后移。
然后 cur 指针按照上一部设置好的位置后移。
循环以上步骤直到 l1 或 l2 为空。
将剩余的 l1 或 l2 接到 cur 指针后边。
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), tail = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummy->next;
    }
};