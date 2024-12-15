/*
给定单向链表的一个节点指针，定义一个函数在O(1)时间删除该结点。

假设链表一定存在，并且该节点一定不是尾节点。

数据范围
链表长度 [1,500]。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//其实是将下一个节点的值赋给自己 然后将下一个节点删除
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto p = node -> next;

        node -> val = p -> val;
        node -> next = p -> next;
        // 这两步的作用就是将 *(node->next) 赋值给 *node，所以可以合并成一条语句：
        // *node = *(node->next);

        delete p;
        p = nullptr;//需要嘛？？？
    }
};

//如果只有一个节点， delete p; p = nullptr;再将链表指向nullptr
//如果删除尾节点，遍历，将前一个置空， delete p; p = nullptr;




//leetcode版本
/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) {
            return head;
        }

        //构造函数 ListNode(int x, ListNode* next) : val(x), next(next) {}
        ListNode* newHead = new ListNode(-1,head);
        ListNode *p = newHead;
        while (p->next) {
            if (p->next->val == val) {
                //删除后直接返回就行了,减少点时间
                p->next = p->next->next;
                return newHead->next;
            }
            p = p->next;
        }
        return nullptr;
    }
};