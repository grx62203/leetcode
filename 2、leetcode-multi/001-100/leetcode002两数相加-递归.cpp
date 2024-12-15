/*
给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

输入：l1 = [0], l2 = [0]
输出：[0]
*/
/*
**递归函数定义**：`addTwoNumbers` 表示将两个链表 `l1` 和 `l2` 相加得到的新链表；
**递归终止条件**：如果 `l1` 和 `l2` 有一个为空，则返回另外一个。
**递归函数内容**：

- 把两个链表节点的值相加（结果记为 `add` ）。把 `add` 模 1010 作为当前的链表节点的值。
- 把两个链表的 `next` 节点相加。（注意：如果当前相加的结果 add >= 10，需要把 next 节点相加得到的结果 `+ 1`。）


递归解法妙在天然地处理好了两个链表不一样长、最终相加结果有进位的情况。
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int target = l1->val + l2->val;
        ListNode* res = new ListNode(target % 10);
        res->next = addTwoNumbers(l1->next, l2->next);
        if (target >= 10)//处理进位
            res->next = addTwoNumbers(res->next, new ListNode(1));
        delete l1, l2;
        return res;
    }
};