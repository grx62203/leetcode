https://blog.csdn.net/Hachi_Lin/article/details/79683018
https://blog.csdn.net/weixin_43736974/article/details/84543970?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-4-84543970-blog-79683018.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-4-84543970-blog-79683018.pc_relevant_aa&utm_relevant_index=6
https://blog.csdn.net/hefrankeleyn/article/details/121071423?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1-121071423-blog-120784291.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1-121071423-blog-120784291.pc_relevant_aa&utm_relevant_index=1

----------------------------------------------------------------------------
--------------------------撒------------------------------------------------




0、
按位  & 有0为0、  | 有1为1、
按数  && 有0为0、 || 有1为1
^ 当前位不相等为1，相等为0


1、、、、异或
x ^ y = |x - y| 执行  按位相减取绝对值
x ^ y ^ y = x   执行  x异或y两次依旧是x

2、、、、按位与
x & 1 = 0       判断  x是奇数
x & y ！= 0     判断  存在二者全1的位
x >> k & 1 = 1  判断  x的二进制表示从右边数第k个是1（从0个开始算），否则是0
x &= (x - 1)    执行  将x的最后一位1变成0
a = x & -x      执行  lowbit()取出x的最后一位1对应的值给a，n -= lowbit(n)将最后的一个位1变成0
x = x & ~ a     执行  将x中对应a二进制中是1的位置全部置0

3、、、、按位移动 
x >> 1 	        执行  x除以2，去掉最后一位
x << 1	        执行  x乘以2，在最后加上一个0
(x << 1) + 1    执行  在最后补位加上一个1


4、、、、按位或
x | 1           把最后一位变成1
x | 1 << i      把从后数第i位强制变成1（从0个开始算）
x = x | ~ a     执行  将x中对应a二进制中是0的位置全部置1

5、、、、二进制加法a、b
x = a ^ b         两个整数x、y做异或^，得到各位相加不进位的运算结果；       
y = (a & b) << 1  两个整数x、y做与&，然后再左移一位，即得到进位的运算结果；  
a=x、b=y           将上面两个结果相加，即递归重复步骤1,2，直至进位的运算结果为0；
返回数x


6、、、、两数之和
----------------------------------------------------------------------------
从低到高遍历位
	a = A & 1 << i 、b = B & 1 << i     取得两个数第i位的值a、b
	sum |= a ^ b ^ Cin                 得到第i位的输出值,累加到sum
	Cout = (a & b)|(a & Cin)|(b & Cin) 得到进位
	Cin = Cout << 1                    得到下一位的进位输入
输出sum为结果
----------------------------------------------------------------------------
把 a 和 b 转换成整型数字 x 和 y，在接下来的过程中，x 保存结果，y 保存进位。
当进位不为 0 时
    计算当前 x 和 y 的无进位相加结果：answer = x ^ y
    计算当前 x 和 y 的进位：carry = (x & y) << 1
    完成本次循环，更新 x = answer，y = carry
返回 x 的二进制形式
----------------------------------------------------------------------------
结果ans的长度最长为a和b长度最大值加一。
把a和b和结果ans三个数字最低位对齐。
    某一位的值为 int val = ai ^ bj ^ carry;
    这位产生的进位 carry = (ai & bj) | (carry & (ai ^ bj));
    当其中一个数，比如b不够时，在高位补0。
然后去掉结果ans高位多余的0。
        int carry = 0;
        for (int i=a.size()-1, j=b.size()-1, k=ans.size()-1; 0<=k; --i,--j,--k) {
            const int ai = 0 <= i ? a[i] - '0' : 0;
            const int bj = 0 <= j ? b[j] - '0' : 0;
            const int val = ai ^ bj ^ carry;
            carry = (ai & bj) | (carry & (ai ^ bj));
            ans[k] = val + '0';
        }
        



7、、、、快速乘
while(y)
	if(y&1)	ans+=x;
	y>>=1, x<<=1;

8、、、、快速幂
while(y)
	if(y&1) ans=ans*x;
	y>>=1, x*=x;




9、、、、二进制计1的数量
x &= x - 1, res++        将x最后一位1置0，然后累加
x -= (x & -x)，res++     将x最后一位1置0，然后累加
res += x & 1, x >>= 1    判断x的最低位是不是1，然后累加
res += ((n >> i) & 1)    判断x的第i位是不是1，然后累加



10、、、、
逻辑运算符 &&，对于 A && B 这个表达式，如果 A 表达式返回 False ，那么 A && B 已经确定为 False ，此时不会去执行表达式 B。
逻辑运算符 ||，对于 A || B 这个表达式，如果 A 表达式返回 True ，那么 A || B 已经确定为 True ，此时不会去执行表达式 B。


11、、、、整数二进制翻转/字符串转换整数
res = res * 10 + x % 10;         答案加上 个位
x /= 10;                         去掉下一个位
res > (INT_MAX - x % 10) / 10    也就是  10*res + x%10 > INT_MAX
int 版本--------------------------------------------------------
while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
    int x = str[k] - '0';  
    if (minus > 0 && res > (INT_MAX - x) / 10) return INT_MAX;
    if (minus < 0 && -res < (INT_MIN + x) / 10) return INT_MIN;
    if (-res * 10 - x == INT_MIN) return INT_MIN;
    res = res * 10 + x;
    k ++ ;
}
res *= minus;
return res;
long long 版本--------------------------------------------------
long long res = 0;
while (k < str.size() && str[k] >= '0' && str[k] <= '9') 
{
    res = res * 10 + str[k] - '0';
    k ++ ;
    if( res > INT_MAX) break;
}      
res *= minus;
if ( res > INT_MAX ) return INT_MAX;
if ( res < INT_MIN ) return INT_MIN;
return res;


12、、、、倍增计算相除
//long可以不考虑最特殊的位置   -2^32
//但int需要考虑，所以int处理的时候，将x与y转换为负数，负数域更大
int 版本，提前避免越界
int divide(int dividend, int divisor) {
        const int HALF_INT_MIN = -1073741824;//限制了超过 2^32
        int x = dividend, y = divisor;
        bool sign = (x > 0) ^ (y > 0);if (x > 0) x = -x;if (y > 0) y = -y; //统一为负数
        vector<pair<int, int>> ys;
        //累计被除数
        for (int t1 = y, t2 = -1; t1 >= x; t1 += t1, t2 += t2) { ys.emplace_back(t1, t2); if (t1 < HALF_INT_MIN) break;}
        int ans = 0;
        for (int i = ys.size() - 1; i >= 0; i--)
            if (x <= ys[i].first) {/*累减除数*/x -= ys[i].first;/*二进制累加商，防止溢出用1ll*/ ans += ys[i].second;}
        if (!sign) {
            if (ans == INT_MIN)  return INT_MAX;//大于INT_MAX的情况可以被提前避免，也可以判别res > (INT_MAX - x) / 10、-res < (INT_MIN + x) / 10
            ans = -ans;}
        return ans;}
long long 版本
int divide(int x, int y) {
        typedef long long LL; vector<LL> exp;  bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;
        LL a = abs((LL)x), b = abs((LL)y);
        //累计被除数，再依次从大到小累减
        for (LL i = b; i <= a; i = i + i) exp.push_back(i);
        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i -- )
            if (a >= exp[i]) {/*累减除数*/a -= exp[i];/*二进制累加商，防止溢出用1ll*/res += 1ll << i; }
        if (is_minus) res = -res;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;//可以直接判别，不用考虑-2^32(int无法表示这个)
        return res;}


13、、、、二进制存储信息 = 一个数就是一个集合 = 表示一个集合中某数是否出现过
//存储某个数是否出现过，a=00000101中代表1、3出现过
a & (1 << 3)   可以验证a表示的集合中是否出现过3，如果出现过，return 1 ，否则有0则0，return 0
a |= (1 << 3)  可以存储a表示的集合中出现过3，即 a = a | (1 << 3), 标记a中出现了3
mask = ~ (x | y | z) & 0x1ff 
    |  为or，有1为1，通过3个或运算我们可以得到一个9位的二进制数字，其中剩下的0 有意义，按照从右边数的位置，留下的 0 表示1-9 可以被插入
    ~ 运算（取反），然后我们用取反后的 1 表示当前位置代表的数字是一个可填入的选项（从右往左依次是1、2、3、、、、）
    & 为按位与 ， 有0为0， 0x1ff为十六进制 ，等同于111111111，再&加强表示？
    表示：先得到可以插入数字的二进制从右到左的表示，再取反为 1 表示， 再有0为0加强
mask && !valid
    &&  按数与    有0为0
    表示：mask存在 且 vaild 为假（0）  时  表达式才是  真（1）
mask &= (mask - 1)
    &  为按位与 有0为0
    mask - 1 在二进制上 最后一个 1 发生变化了，后面的 0 也发生变化了
    表示：将 mask 的最低位一个 1 ，变成了 0 ，表示清除某一项，在这里表示 最后一个 1 代表 的数字 接下来 不被考虑了
digitMask = mask & (-mask)
    -mask 表示  ～mask+1 ，这个时候只有 最低位 的 1 与众不同
    表示：除了最低位的 1 其他都置0 ，得到一个数，只保留了最低位的 
digit = __builtin_ctz(digitMask);
    获取当前这一位后面有几个0，便转化为几，方便后面移动标记某一位被用过

14、、、、二进制+1
如果最后是连续的0，找到前面连续的1，把最前面的1与再前面的0换位置，后面剩下的1放到最末尾
如果最后是连续的1，把最前面的1与再前面的0换位置
        int j = 0;
        //每次循环都要从当前k个1的二进制跳到 字典序排列的下一个也是k个1的二进制。再一一加入答案
        while (j < k) {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
            // 我们需要把 [0, t - 1] 区间内的每个位置上的内容重置成 [1, t]范围的内容 = 后面剩下的1放到最末尾/不操作
                //最低位是1，找到最后一个1的位置
                //最低位是0，找到了接下来的连续1位的最后一个1的位置
            while (j < k && temp[j] + 1 == temp[j + 1]) {
                temp[j] = j + 1;
                ++j;
            }
            // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
                //然后将这个选择+1，也就是本来第五位是1第六位是0，结果变成第六位是1的一个情况（第五位前面以及被修改为第六位的0了）
            ++temp[j];
        }

15、、、、