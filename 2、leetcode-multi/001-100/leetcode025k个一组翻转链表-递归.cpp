/*
给你一个链表，每 *k* 个节点一组进行翻转，请你返回翻转后的链表。

*k* 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 *k* 的整数倍，那么请将最后剩余的节点保持原有顺序。

**进阶：**

- 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
- **你不能只是单纯的改变节点内部的值**，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]

- 列表中节点的数量在范围 `sz` 内
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for (int i=0; i < k; ++i) {          // 判断“满载”
            if (!node) return head;
            node = node->next;
        }
        auto res = reverse(head, node);      // 翻转“满载”车箱
        head->next = reverseKGroup(node, k); // 递归处理下节车箱
        return res; // 返回当前翻转完车箱的车头位置
    }
private:
    // 翻转车箱元素
    ListNode* reverse(ListNode* left, ListNode* right) {
        auto pre = right;
        while (left != right) {
            auto node = left->next;
            left->next = pre;
            pre = left, left = node;
        }//最后left->next 是right，但出去就会被更改为下节车厢的返回值
        return pre;
    }
};


//
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto isOk = head;
        for (int i = 0; i < k; ++i) {
            if (!isOk) return head;
            isOk = isOk->next;
        }
        ListNode *cur = head, *pre = nullptr, *next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
            //结束时，将车厢的旧车头（新车尾）的指向更新为空指针，
            //此时，pre是当前车厢的旧车尾（新车头），cur是下一节车厢的车头
        }
        head->next = reverseKGroup(cur, k);//更新前一节车厢的新尾巴的下一个为后一节车厢的新车头
        return pre;
    }
};