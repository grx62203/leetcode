https://blog.csdn.net/android_cmos/article/details/52887028?spm=1001.2101.3001.6650.13&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-13-52887028-blog-107822549.pc_relevant_multi_platform_whitelistv1&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-13-52887028-blog-107822549.pc_relevant_multi_platform_whitelistv1&utm_relevant_index=18
一、二叉树的遍历概念

    1.  二叉树的遍历是指从根结点触发，按照某种次序依次访问二叉树中所有结点，使得每个结点被访问一次且仅被访问一次。

(1). 前(先)序遍历

前序遍历：若二叉树为空，则空操作返回，否则先访问根结点，然后前序遍历左子树，再前序遍历右子书。

特点：①. 根----->左------->右

           ②. 根据前序遍历的结果可知第一个访问的必定是root结点。


(2). 中序遍历

中序遍历：若二叉树为空，则空操作返回，否则从根结点开始（注意并不是先访问根结点），中序遍历根结点的左子树，然后访问根结点，最后中序遍历右子树。

特点：①. 左----->根------->右

           ②. 根据中序遍历的结果，再结合前序遍历的root结点去划分root结点的左右子树。


(3). 后序遍历

后序遍历：若二叉树为空，则空操作返回，否则从左到右先叶子结点后结点的方式遍历访问左右子树，最后访问根结点。

特点：①. 左------>右------>根

           ②. 根据后序遍历的结果可知最后访问的必定是root结点。


(4). 层序遍历

层序遍历：若二叉树为空，则空返回，否则从树的第一层，即根结点开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问。

特点：①. 从左到右，从上到下

           ②. 可知第一个访问的必定是root结点
————————————————
版权声明：本文为CSDN博主「android_cmos」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/android_cmos/article/details/52887028

二、根据遍历结果去推其他的遍历结果

相信这种情况下，考题的最多，一是考查如何递归倒推；二是节约试卷版面，画图也麻烦。

1.根据前序遍历、中序遍历，求后序遍历

例：
前序遍历:         GDAFEMHZ
中序遍历:         ADEFGHMZ
画树求法：
第一步，根据前序遍历的特点，我们知道根结点为G


第二步，观察中序遍历ADEFGHMZ。其中root节点G左侧的ADEF必然是root的左子树，G右侧的HMZ必然是root的右子树。


第三步，观察左子树ADEF，左子树的中的根节点必然是大树的root的leftchild。在前序遍历中，大树的root的leftchild位于root之后，所以左子树的根节点为D。


第四步，同样的道理，root的右子树节点HMZ中的根节点也可以通过前序遍历求得。在前序遍历中，一定是先把root和root的所有左子树节点遍历完之后才会遍历右子树，并且遍历的左子树的第一个节点就是左子树的根节点。同理，遍历的右子树的第一个节点就是右子树的根节点。


第五步，观察发现，上面的过程是递归的。先找到当前树的根节点，然后划分为左子树，右子树，然后进入左子树重复上面的过程，然后进入右子树重复上面的过程。最后就可以还原一棵树了。

该步递归的过程可以简洁表达如下：

1 确定根,确定左子树，确定右子树。
2 在左子树中递归。
3 在右子树中递归。
4 打印当前根。
————————————————
版权声明：本文为CSDN博主「android_cmos」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/android_cmos/article/details/52887028

2.  已知中序和后序遍历，求前序遍历
依然是上面的题，这次我们只给出中序和后序遍历：
中序遍历:       ADEFGHMZ
后序遍历:       AEFDHZMG
画树求法：
第一步，根据后序遍历的特点，我们知道后序遍历最后一个结点即为根结点，即根结点为G。

第二步，观察中序遍历ADEFGHMZ。其中root节点G左侧的ADEF必然是root的左子树，G右侧的HMZ必然是root的右子树。

第三步，观察左子树ADEF，左子树的中的根节点必然是大树的root的leftchild。在前序遍历中，大树的root的leftchild位于root之后，所以左子树的根节点为D。

第四步，同样的道理，root的右子树节点HMZ中的根节点也可以通过前序遍历求得。在前后序遍历中，一定是先把root和root的所有左子树节点遍历完之后才会遍历右子树，并且遍历的左子树的第一个节点就是左子树的根节点。同理，遍历的右子树的第一个节点就是右子树的根节点。

第五步，观察发现，上面的过程是递归的。先找到当前树的根节点，然后划分为左子树，右子树，然后进入左子树重复上面的过程，然后进入右子树重复上面的过程。最后就可以还原一棵树了。该步递归的过程可以简洁表达如下：
1 确定根,确定左子树，确定右子树。
2 在左子树中递归。
3 在右子树中递归。
4 打印当前根。
这样，我们就可以画出二叉树的形状，如上图所示，这里就不再赘述。

那么，前序遍历:         GDAFEMHZ


关于二叉树，多练习几次就熟悉了。


————————————————
版权声明：本文为CSDN博主「android_cmos」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/android_cmos/article/details/52887028