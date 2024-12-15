/*
请实现一个函数可以复制一个复杂链表。

在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null。

注意：

函数结束后原链表要与输入时保持一致。
数据范围
链表长度 [0,500]。
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
//O(n)
//使用hash存储 key = 源链表节点，value = 目标链表节点，遍历源链表，判断每个节点和random节点是否在hash表中，如果不存在则创建
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        unordered_map<ListNode*, ListNode*> hash;
        hash[nullptr] = nullptr;
        auto dup = new ListNode(-1), tail = dup;

        while(head)
        {
            if(!hash.count(head)) hash[head] = new ListNode(head->val);
            if(!hash.count(head->random)) hash[head->random] = new ListNode(head->random->val);

            tail->next = hash[head];
            tail->next->random = hash[head->random];
            //逐个遍历
            tail = tail->next;
            head = head->next;
        }

        return dup->next;
    }
};
