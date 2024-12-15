/*
输入一个链表，输出该链表中倒数第 k 个结点。

注意：

k >= 1;
如果 k 大于链表长度，则返回 NULL;
数据范围
链表长度 [0,30]。
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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        if (pListHead==NULL) return NULL;
        vector<ListNode*> arr;
        // memset(arr,0,sizeof(arr));

        ListNode* p =  pListHead;
        while(p!=NULL){
            arr.push_back(p);
            p = p->next;
        }
        if(k>arr.size()) return NULL;
        int id = arr.size() - k;
        return arr[id];
    }
};
