/*
输入一个链表的头结点，按照 从尾到头 的顺序返回节点的值。

返回的结果用数组存储。

数据范围
0≤ 链表长度 ≤1000。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//时间:O(n)
//空间：O(n)
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        if (!head) return {};
        auto res = printListReversingly(head->next);
        res.push_back(head->val);
        return res;
    }
};