/*
给你一个链表，每 *k* 个节点一组进行翻转，请你返回翻转后的链表。

*k* 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 *k* 的整数倍，那么请将最后剩余的节点保持原有顺序。

**进阶：**

- 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
- **你不能只是单纯的改变节点内部的值**，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]

- 列表中节点的数量在范围 `sz` 内
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*思路
是否有k个
    在这k内
    	前后指向反转,再继续移动窗口，
*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1); dummy->next = head;
        for (auto p = dummy;;) {        //p一直是上一节车厢新的尾巴
            auto q = p;  for (int i = 0; i < k && q; i ++ ) q = q->next;if (!q) break;//判断够不够k个元素 
            auto a = p->next, b = a->next;//旧车厢长度k的第1、2个，然后翻转后第1个会是新车厢的最后一个
            for (int i = 0; i < k - 1; i ++ ) {
                auto c = b->next;       //第三个
                b->next = a;            //2指向1
                a = b, b = c;           //此时21、3456中间断裂了，原窗口12变成了新窗口23，下一次就变成了321、4567
            }   //因为每一次循环断裂一处，从第2个后断裂一直到第k个，也就是需要k-1次的循环。结束时k、k+1时窗口，k是新头、k+1是下一节车厢的旧头
            auto c = p->next;           //旧车厢的头=新车厢的尾巴
            p->next = a, c->next = b;   //上一节车厢的尾巴指向了旧车厢的尾巴k=新车厢的头，旧车厢的头=新车厢的尾巴指向下一节车厢的旧头
            p = c;                      //p再一次指向了上一节车厢新的尾巴
        }
        return dummy->next;             //返回第一节车厢新的头
    }
};


// pre 指向 需要翻转的 局部链表的 第1个结点 的 之前的结点
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1), pre = dummy;
        dummy->next = head;

        // 改成 while(1)也可, 因为跳出循环是靠下面的 break.
        // while(head)可以特判 head == null 情况, 不用等到下面break 就提前跳出
        // while(pre->next) 可以特判 head == null 和 pre->next == null 的情况
        while (pre->next) {
            // 1. 判断是否 还有 k 个结点
            auto q = pre->next;
            for (int i = 1; i < k && q; i ++ ) q = q->next; // 能否移动 k - 1 次
            if (!q) break; // 跳出 for循环, 要么 1.移动了k-1次,q不为空; 2.q为空,不够k个

            // 1. 判断是否 还有 k 个结点
            // int cnt = 0;
            // for (auto q = pre->next; q && cnt <= k; q = q->next) cnt ++ ;
            // if (cnt < k ) break;

            // 2.1 局部翻转链表
            auto a = pre->next, b = a->next;
            for (int i = 1; i < k; i ++ ) { // k-1 次. 注意 不能while(--k), k值 不能变动
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }

            // 2.2 处理 局部链表 首尾结点 处的 连接情况
            head = pre->next; // 用 head 暂存 pre->next
            pre->next = a, head->next = b;

            // 2.3 pre 更新为 下一段需要局部翻转的链表段的 前一个结点, 即 b之前的结点 head
            pre = head; // pre需要指向b之前的结点, b之前的结点是 head 而不是 a !!!
        }

        return dummy->next;
    }
};
