/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` 按 **升序** 排列
- `lists[i].length` 的总和不超过 `10^4`
*/


// 合并两个有序链表 迭代法：时间O(n + m), 空间O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // dummy是指针,下面要return dummy->next. new指针要开辟内存. 内存消耗 大
        // auto dummy = new ListNode(-1), cur = dummy;

        // dummy是ListNode 型, 不是ListNode * 型, 要return dummy.next. 内存消耗 小
        ListNode dummy, *cur = &dummy; 

        while (l1 && l2) // 可以把 while的 "{}" 去掉, if-else 算是一对语句
            if (l1->val < l2->val) cur = cur->next = l1, l1 = l1->next;
            else cur = cur->next = l2, l2 = l2->next;

        cur->next = l1 ? l1 : l2;

        // return dummy->next; // dummy 是指针类型, 是 ListNode * 型
        return dummy.next; // dummy 不是指针类型, 是 ListNode 型
    }
};



// 分治合并：时间 O(kn * logk), 递归栈空间 O(logk)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        // dummy是指针,下面要return dummy->next. new指针要开辟内存. 内存消耗 22.1MB
        // auto dummy = new ListNode(-1), cur = dummy;

        // dummy是ListNode 型, 不是ListNode * 型, 要return dummy.next. 内存消耗 12.7MB
        ListNode dummy, *cur = &dummy; 

        while (a && b) // 可以把 while的 "{}" 去掉, if-else 算是一对语句
            if (a->val < b->val) cur = cur->next = a, a = a->next;
            else cur = cur->next = b, b = b->next;

        cur->next = a ? a : b;

        // return dummy->next; // dummy 是指针类型, ListNode * 型
        return dummy.next; // dummy 不是指针类型, ListNode 型
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l]; // 递归结束条件, [l, r]中 只剩下一个链表, l==r
        int mid = (l + r) >> 1;
        //对两个merge的结果=两个链表进行两个链表合并操作，然后返回一个链表
        //每一个merge都是分治的过程，但是返回结果被用在了上游的返回计算过程中
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr; // 特判 n == 0
        return merge(lists, 0, n - 1); // 不用特判 n 为 1
    }
};


//如果 想 合并 上面的 ListNode* mergeKLists() 和 ListNode* merge(). 参考 wzc1995 改成如下代码所示，不过内存消耗 增加了，变成了 28.5MB。
// 合并 上面的 ListNode* mergeKLists() 和 ListNode* merge(). 内存消耗: 28.5MB
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (!n) return nullptr;
    if (n == 1) return lists[0];

    int mid = n >> 1;

    auto left = vector<ListNode*>(lists.begin(), lists.begin() + mid);
    auto right = vector<ListNode*>(lists.begin() + mid, lists.end());

    auto l1 = mergeKLists(left);
    auto l2 = mergeKLists(right);

    return mergeTwoLists(l1, l2);
}