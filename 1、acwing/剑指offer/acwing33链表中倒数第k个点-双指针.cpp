/*
输入一个链表，输出该链表中倒数第 k 个结点。

注意：

k >= 1;
如果 k 大于链表长度，则返回 NULL;
数据范围
链表长度 [0,30]。
*/
/*
**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* a, int k) {
        auto s = a;
        //复制的第二个链表比第一个快k步
        for (int i = 0; i < k; i++) {
            if (s)
                s = s->next;
            if (!s && i < k - 1)
                return NULL;
        }
        //然后同时走，如果第二个走到头结束，那么第一个走到了距离结尾为k的节点
        while (s) {
            a = a->next;
            s = s->next;
        }
        return a;
    }
};
