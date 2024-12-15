/*
输入两个链表，找出它们的第一个公共结点。

当不存在公共节点时，返回空节点。

数据范围
链表长度 [1,2000]。

样例
给出两个链表如下所示：
A：        a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

输出第一个公共节点c1
*/
//leetcode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//leetcode
//java
public class Solution {
    public ListNode getIntersectionNode(ListNode a, ListNode b) {
        for (ListNode h1 = a; h1 != null ; h1 = h1.next) {
            for (ListNode h2 = b; h2 != null ; h2 = h2.next) {
                if (h1 == h2) return h1;
            }
        }
        return null;
    }
};