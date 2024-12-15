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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*c++优先队列(priority_queue)用法详解，
优先队列定义：priority_queue<Type, Container, Functional>
for (auto l : lists) if (l) heap.push(l); 优先队列 只是把 每个链表的 头结点的地址 push进去了，而不是 把 整个链表 push进去。
因为 优先队列中存的是 链表头结点的地址, 我们要比较的是结点的值 而不是 地址，所以 要自己定义 Cmp 比较 结点的值。
重载 "()" 原因参考 y总代码评论区 ：STL容器 在比较的时候用的是 结构体的小括号运算符。
return a->val > b->val; ，注意此处 小根堆 是 ‘>’, a在b前面 表示 a在b下面。
*/
//时间 O(kn * logk), 空间 O(k)
    
class Solution {
public:
	//传入的比较函数
    struct Cmp {
    	//重载括号
        //因为stl容器在比较的时候，使用的是struct的小括号
        bool operator() (ListNode* a, ListNode* b) {
        	//本来是大的在前面，反转一下，把小的放前面，也就是将大根堆变成小根堆
            //比较函数返回true 表示，在堆中，a在b的下面
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	// 优先队列 定义：priority_queue<Type, Container, Functional>
        // 因为 优先队列中存的是 链表头结点的地址, 我们要比较的是结点的值 而不是 地址
        // 所以 要自己定义 Cmp 比较 结点的值
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        
        //两种写法
        //auto dummy = new ListNode(-1), cur = dummy;  return dummy->next；
        // ListNode dummy, *cur = &dummy;  return dummy.next;
        auto dummy = new ListNode(-1), tail = dummy;

        //防止空链表，插入所有的链表到堆
        //只是把每个链表的头结点的地址push进去了，而不是把整个链表push进去。
        for (auto l : lists) if (l) heap.push(l);

        while (heap.size()) {

            auto t = heap.top();
            heap.pop();
			//把当前节点放到尾节点，再更新
            tail = tail->next = t;
            if (t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};



//
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for (auto node : lists) {
            if (node) q.push(node);
        }
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }