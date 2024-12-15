/*
给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**进阶：**你能尝试使用一趟扫描实现吗？
*/


//链表题目，头节点特判。使用虚拟头节点

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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        //建立虚拟头节点，行使头节点的功能
        dummy->next = head;

        int n = 0;
        for (auto p = dummy; p; p = p->next) n ++ ;
        //求得链表的总长度(包括虚拟头节点)

        auto p = dummy;
        for (int i = 0; i < n - k - 1; i ++ ) p = p->next;
        //此时p跳了 n-k-1 步，跳到了第 n-k 个点
        p->next = p->next->next;

        return dummy->next;
    }
};



class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)   cur = cur->next;
        cur->next = cur->next->next;//删除
        ListNode* ans = dummy->next;//作为返回
        delete dummy;
        return ans;
    }
};