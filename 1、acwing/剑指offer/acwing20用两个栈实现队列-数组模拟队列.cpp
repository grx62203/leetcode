/*
请用栈实现一个队列，支持如下四种操作：

push(x) – 将元素x插到队尾；
pop() – 将队首的元素弹出，并返回该元素；
peek() – 返回队首元素；
empty() – 返回队列是否为空；
注意：
	你只能使用栈的标准操作：push to top，peek/pop from top, size 和 is empty；
	如果你选择的编程语言没有栈的标准库，你可以使用list或者deque等模拟栈的操作；
	输入数据保证合法，例如，在队列为空时，不会进行pop或者peek等操作；
数据范围
	每组数据操作命令数量 [0,100]。
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    int a[110];
    int idx1;
    int idx2;
    MyQueue() {
        idx1 = 0;
        idx2 = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        a[idx1 ++] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        return a[idx2 ++];
    }

    /** Get the front element. */
    int peek() {
        return a[idx2];
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return idx2 == idx1 ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop()s;
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 