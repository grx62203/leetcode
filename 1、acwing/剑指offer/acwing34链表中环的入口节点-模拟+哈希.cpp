/*
给定一个链表，若其中包含环，则输出环的入口节点。

若其中不包含环，则输出null。

数据范围
节点 val 值取值范围 [1,1000]。
链表长度 [0,500]。
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
#include <unordered_map>
class Solution {
public:
    bool st[1010];
    ListNode *entryNodeOfLoop(ListNode *head) {
      unordered_map<ListNode *, int>   mp;

      int cnt = 0;
      while(head)
      {
          if (mp[head])   return head;
          mp[head] = cnt ++;

          head = head -> next;
      }

      return NULL;
    }
};
