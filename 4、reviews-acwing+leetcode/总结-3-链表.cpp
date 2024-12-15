//链表中的加法题    提示：不要因为简单而轻视这类题目，多思考边界条件及其变型！
2.两数相加：反向存放、反向输出。
02.05.链表求和：与上一题相比，有更多的边界条件。
445.两数相加 II：正向存放，正向输出。推荐看@sweetiee的简单Java


//反转链表的题     注明：以下某些题目是可以用（但不限于用）反转链表思路的题目。
206.反转链表 和   Offer 24.反转链表：一模一样的基础题，建议不懂反转链表套路的同学翻一翻这两题的题解区，找到对应语言的大佬们看看他们对此的解释（有画图很棒的大佬）。
92. 反转链表 II：反转从位置m到n的链表。请使用一趟扫描完成反转。
Offer 06.从尾到头打印链表：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
143.重排链表：不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
25.K 个一组翻转链表：每k个节点一组进行翻转，返回翻转后的链表。PS：困难题看不懂的时候及时放弃。
234.回文链表 和   02.06.回文链表：判断一个链表是否为回文链表。

//相交链表的题      注明：这三题可以用同一个代码，大家可以自行揣摩题目的区别，反正代码是没啥区别。
160. 相交链表
Offer 52. 两个链表的第一个公共节点
02.07. 链表相交

//环形链表
141. 环形链表：判断有没有环
142. 环形链表 II：返回链表开始入环的第一个节点
02.08. 环路检测：跟上题一样

//倒数第k个节点
注明：都是用快慢指针法
Offer 22.链表中倒数第k个节点：返回的是节点
02.02.返回倒数第 k 个节点：返回的是节点的值（val）

提升：尝试用快慢指针法找单链表的中点。

//删除链表中的某个节点      注明：注意题目之间的差异和边界条件。好几题的题目长的差不多，点进去以后略有不同。
Offer 18.删除链表的节点
237.删除链表中的节点 和   02.03. 删除中间节点
19.删除链表的倒数第N个节点
83.删除排序链表中的重复元素：给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
82.删除排序链表中的重复元素 II：给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中没有重复出现的数字。
02.01.移除重复节点：移除未排序链表中的重复节点。保留最开始出现的节点。
203.移除链表元素：删除链表中等于给定值val的所有节点。

//排序链表
147.对链表进行插入排序：对链表进行插入排序。
148.排序链表：给你链表的头结点 head ，请将其按升序排列并返回排序后的链表 。提升：如何输出按降序排列的链表。

//合并链表     注明：第一题必会，后两题不会就算了吧，别纠结了。
Offer 25. 合并两个排序的链表和21. 合并两个有序链表：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
1669. 合并两个链表：数字比较大的多半是竞赛题
23. 合并K个升序链表：困难题，量力而行

//分隔链表      注明：这是一个力扣迷惑现象：同名不同题，不同名同题。
86. 分隔链表 和       02.04. 分割链表：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
725. 分隔链表：给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。





--------------------------------------------------------------------------------------------------------------
--------------------------虚拟头节点---------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------------
--------------------------虚拟头节点---------------------------------------------------------------------------
1-1、建立虚拟头节点new，行使头节点的功能
    auto dummy = new ListNode(-1);dummy->next = head;
    return dummy->next;
1-2、建立虚拟头节点new，同时进行delete
ListNode* dummy = new ListNode(0, head);
//某操作
    int length = getLength(head);
    ListNode* cur = dummy;
    for (int i = 1; i < length - n + 1; ++i)   cur = cur->next;
    cur->next = cur->next->next;//删除
//某操作
    ListNode* ans = dummy->next;//作为返回
    delete dummy;
    return ans;
1-3、指针内存大、类型内存小
// dummy是指针,下面要return dummy->next. new指针要开辟内存. 内存消耗 大
    auto dummy = new ListNode(-1), cur = dummy;
// dummy是ListNode 型, 不是ListNode * 型, 要return dummy.next. 内存消耗 小
    ListNode dummy, *cur = &dummy;
--------------------------------------------------------------------------------------------------------------
--------------------------求链表长度---------------------------------------------------------------------------
//求得链表的总长度(包括虚拟头节点)
    for (auto p = dummy; p; p = p->next) length ++ ; 
    while (head) { ++length; head = head->next;}
//此时p跳了 n-k-1 步，跳到了第 n-k 个点
    for (int i = 0; i < n - k - 1; i ++ ) p = p->next;
--------------------------------------------------------------------------------------------------------------
--------------------------合并有序链表-------------------------------------------------------------------------
合并2个有序链表-递归
/*新建头部的保护结点 dummy，设置 cur 指针指向 dummy。
若当前 l1 指针指向的结点的值 val 比 l2 指针指向的结点的值 val 小，则令 cur 的 next 指针指向 l1，且 l1 后移；否则指向 l2，且 l2 后移。
然后 cur 指针按照上一部设置好的位置后移。
循环以上步骤直到 l1 或 l2 为空。
将剩余的 l1 或 l2 接到 cur 指针后边。*/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), tail = dummy;
        while (l1 && l2) {if (l1->val < l2->val) {tail = tail->next = l1;l1 = l1->next; } 
        				  else 					 {tail = tail->next = l2;l2 = l2->next; }}
        if (l1) tail->next = l1; if (l2) tail->next = l2;
        return dummy->next;}
合并2个有序链表-迭代
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)        return l2;
        else if (l2 == nullptr)   return l1;
        else if (l1->val < l2->val) { l1->next = mergeTwoLists(l1->next, l2); return l1; } 
        else                        { l2->next = mergeTwoLists(l1, l2->next); return l2; } }
合并k个有序链表
    暴力枚举合并链表、分治合并链表、小根堆合并链表头、
--------------------------------------------------------------------------------------------------------------
--------------------------两两交换节点-迭代+递归----------------------------------------------------------------
//两两交换节点-迭代
    for (auto p = dummy; p->next && p->next->next;) {
	   auto a = p->next, b = a->next;
	   //p是0、a是1、b是2、b->next是3，先备份12，中间一对变换位置，则先连接前再连接后再连接中
	   p->next = b;           //0指向了2
	   a->next = b->next;     //1指向了3
	   b->next = a;           //2指向了1
	   p = a;                 //把p等效了原来的1，此时原来的1234变成立2134，然后就操作1345，p指向1，然后交换的是34
}
//两两交换节点-递归
    ListNode* swapPairs(ListNode* head) {
	   if (head == nullptr || head->next == nullptr) return head;  
	   ListNode* newHead = head->next;        //备份了2 = 当前链表的新头节点
	   head->next = swapPairs(newHead->next); //1指向了   新链表的新头节点（新链表如果大于2，返回4，如果等于1，返回3），形成了一个1开头的链表
	   newHead->next = head;                  //2指向了1，然后2后面续上了1开头的链表
	   return newHead;                        //返回当前链表的新头节点=2
    } 
--------------------------------------------------------------------------------------------------------------
--------------------------k个一组翻转链表-迭代+递归-------------------------------------------------------------
//k个一组翻转链表-迭代
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
        auto c = p->next;           //p是上一节车厢的尾巴，指向的是 旧车厢的头=新车厢的尾巴，把新车厢的尾巴取出来
        p->next = a, c->next = b;   //上一节车厢的尾巴指向了旧车厢的尾巴=新车厢的头，旧车厢的头=新车厢的尾巴指向下一节车厢的旧头（因为最后断ab，a是前车厢，b是后车厢的）
        p = c;                      //p再一次成为了了上一节车厢新的尾巴
    }
    return dummy->next;             //返回第一节车厢新的头
}
//k个一组翻转链表-递归
ListNode* reverseKGroup(ListNode* head, int k) {
	auto node = head;
	for (int i=0; i < k; ++i) { if (!node) return head;	node = node->next;}
	auto res = reverse(head, node);      // 翻转当前“满载”车箱，返回当前车厢旧尾巴=新头
	head->next = reverseKGroup(node, k); // 递归处理下节车箱，当前车厢的旧头成了新尾巴，指向了下节车厢
	return res;                          // 返回当前翻转完车箱的车头位置
}
ListNode* reverse(ListNode* left, ListNode* right) {//left是车厢第一个，right是下一节车厢第一个
    auto pre = right;                
    while (left != right) {//每次取出第二个，将第一个指向前一个，也就是将窗口=2断开，然后向后移动窗口，直到窗口到了终点，最后一次断开的是两节车厢，没有再连接
        auto node = left->next;
        left->next = pre;
        pre = left, left = node;
    }//最后left->next 是right，但出去就会被更改为下节车厢的返回值
    return pre;                                    //返回的是这一节车厢的最后一个，并不是传进来的right
}



--------------------------------------------------------------------------------------------------------------
--------------------------k个一组翻转链表-迭代+递归-------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--------------------------k个一组翻转链表-迭代+递归-------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
--------------------------k个一组翻转链表-迭代+递归-------------------------------------------------------------