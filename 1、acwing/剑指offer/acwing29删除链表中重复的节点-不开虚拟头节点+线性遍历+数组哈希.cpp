/*
在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留。

数据范围
链表中节点 val 值取值范围 [0,100]。
链表长度 [0,100]。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//wwb
class Solution {
public:
    bool st1[210];
    bool st2[210];
    ListNode* deleteDuplication(ListNode* head) {
        if (head == NULL || head -> next == NULL)   return head;  
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);

        ListNode* temp = head;
        while(temp)
        {
            if (st1[temp -> val])     st2[temp -> val] = true;
            st1[temp -> val] = true;
            temp = temp  -> next;
        }


       // temp = head; ListNode* last = ans;
        ListNode *ans = new ListNode(0);
         ListNode* last = ans;
        ans -> next = head;
        //ListNode *p = ans;
        //ans -> next = NULL;

        temp = ans -> next;
        while(temp)
        {
            if (st2[temp -> val])
            {
                temp = temp -> next;
            }
            else
            {
                last -> next = temp;
                last = temp;
                temp = temp -> next;
            }
        }
        last -> next = temp;

        return ans -> next;
    }
};
