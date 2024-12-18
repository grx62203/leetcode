https://leetcode.cn/problems/count-of-smaller-numbers-after-self/solution/shu-zhuang-shu-zu-by-liweiwei1419/
1、预备知识：前缀和数组
	知道前缀和就可以求区间和
	这是因为不同规模的区间和有重复的部分，相减以后就得到了区间和。
2、把预处理的数据组织成「树形结构」，有两种数据结构：
	线段树：高效处理「区间和」查询（不仅仅可以处理和、还可以处理区间最值等），单点修改；
	树状数组：高效处理「前缀和」查询，单点修改。
「线段树」和「树状数组」一样，都是对原始输入数组进行了预处理，使得在真正需要查询数据的时候，我们只需要看「预处理数组」的部分信息即可，由于组织成树形结构，「修改」和「查询」的时间复杂度都是 O(\log N)O(logN)。
3、注意：
	「线段树」和「树状数组」不能处理输入数组的长度有增加或者减少的情况。
	线段树是一棵二叉树
	树状数组是多叉树
	和「堆」一样，树状数组的 0 号下标不放置元素，从 1 号下标开始使用。
4、下标写成二进制的形式
	最低位的 1 以及后面的 0 表示了预处理数组 C 管理了多少输入数组 A 的元素。
	「树状数组」组织成的树是有层级的，下标的二进制表示的最低位 1 后面的 0 的个数决定了，当前结点在第几层；
	这样组织数据，从叶子结点到父结点是可以通过一个叫做 lowbit 的函数计算出来，并且可以知道小于等于当前下标的同一层结点的所有结点，为了说清楚这一点，需要有一定的篇幅。
5、lowbit 函数
	截取一个正整数的二进制表示里的最低位的 1 和它后面的所有的 0。
	lowbit(x) = x & (-x);
	这里 x 一定是正整数，即 x >= 1；
	这里 & 表示按位与运算；
	-x 也可以写成 (~x + 1) ，这里 ~ 表示「按位取反」。这是负数的定义，负数用补码表示，它的值等于这个负数的绝对值按位取反以后再加 11，因此 lowbit(x) = x & (~x + 1);。
6、单点更新
	「单点更新」从孩子结点到父亲结点，沿途所有的结点都需要更新；
	从孩子结点到父亲结点，就是不断加上当前下标的 lowbit 值，产生进位。
	/**
	 * 单点更新
	 *
 	* @param i     原始数组索引 i
	 * @param delta 变化值 = 更新以后的值 - 原始值
 	*/
	public void update(int i, int delta) {
	    // 从下到上更新，注意，预处理数组，比原始数组的 len 大 1，故 预处理索引的最大值为 len
 	   while (i <= len) {
 	       tree[i] += delta;
  	      i += lowbit(i);
  	  }
	}
	public static int lowbit(int x) {
 	   return x & (-x);
	}
7、前缀和查询
	7 的二进制 (0111)
	这三部分可以看成 (0100) 、(0010) 、(0001)这 3 部分之和，
	分别表示 4 个元素 + 2 个元素 + 1 个元素，正好是 lowbit 值一直减，减到 0 为止，每减去一个 lowbit 值，消去一个 1。
	/**
 	* 查询前缀和
 	*
 	* @param i 前缀的最大索引，即查询区间 [0, i] 的所有元素之和
 	*/
	public int query(int i) {
 	   // 从右到左查询
   		int sum = 0;
    	while (i > 0) {
     		sum += tree[i];
      		i -= lowbit(i);
   		}
    	return sum;
	}
8、树状数组的初始化
	update 操作的第 22 个参数是一个变化值，而不是变化以后的值。
	因为我们的操作是逐层向上汇报，汇报变更值会让我们的操作更加简单
	public FenwickTree(int[] nums) {
    	this.len = nums.length + 1;
    	tree = new int[this.len + 1];
   		for (int i = 1; i <= len; i++) {
       		update(i, nums[i]);
    	}
	}
