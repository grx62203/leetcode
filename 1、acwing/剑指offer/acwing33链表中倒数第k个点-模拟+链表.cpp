/*
输入一个链表，输出该链表中倒数第 k 个结点。

注意：

k >= 1;
如果 k 大于链表长度，则返回 NULL;
数据范围
链表长度 [0,30]。
*/
/*
由于单链表不能索引到前驱节点，所以只能从前往后遍历。

我们一共遍历两次：

第一次遍历得到链表总长度 n；
链表的倒数第 kk个节点，相当于正数第 n−k+1 个节点。所以第二次遍历到第 n−k+1 个节点，就是我们要找的答案。
注意当 k>n 时要返回nullptr。
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
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n < k) return nullptr;
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        return p;
    }
};
