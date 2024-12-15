//显式递归
public static void afterOrder(BinaryTree root) {
        if (root == null)
            throw new IllegalArgumentException("请输入一棵树");
        if (root.getLeft() != null)
            afterOrder(root.getLeft());
        if (root.getRight() != null)
            afterOrder(root.getRight());
        System.out.print(root.getData()+"\t");
    }
}


//一个栈
 public static void afterOrderUnRecurUseOneStack(BinaryTree root) {
        if (root != null) {
            Stack<BinaryTree> stack = new Stack<>();
            BinaryTree pre = null, curr;
            stack.push(root);
            while (!stack.isEmpty()){
                curr = stack.peek();
                if (pre != curr.getRight() && pre != curr.getLeft() && curr.getLeft() != null){
                    stack.push(curr.getLeft());
                } else if (pre != curr.getRight() && curr.getRight() != null){
                    stack.push(curr.getRight());
                } else {
                    System.out.print(stack.pop().getData()+"\t");
                    pre = curr;
                }
            }
        }
    }

//两个栈
public static void afterOrderUnRecur(BinaryTree root) {
        if (root == null)
            throw new IllegalArgumentException("请输入一棵树");
        if (root != null) {
            Stack<BinaryTree> stack1 = new Stack<>();
            Stack<BinaryTree> stack2 = new Stack<>();
            stack1.push(root);
            while (!stack1.isEmpty()) {
                root = stack1.pop();
                stack2.push(root);
                if (root.getLeft() != null)
                    stack1.push(root.getLeft());
                if (root.getRight() != null)
                    stack1.push(root.getRight());
            }
            while (!stack2.isEmpty()) {
                System.out.print(stack2.pop().getData() + "\t");
            }
        }
    }

————————————————
版权声明：本文为CSDN博主「KodeWang」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u013310517/article/details/77985772