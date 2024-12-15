一、概念
bitset可以说是一个多位二进制数，每八位占用一个字节，因为支持基本的位运算，所以可用于状态压缩，n位bitset执行一次位运算的时间复杂度可视为n/32.

二、基本操作

1.定义：
bitset< n > s;
表示一个n位的二进制数，<>中填写位数；

2.位运算操作符：
~s: 返回对s每一位取反后的结果；
&，|，^：返回对两个位数相同的bitset执行按位与、或、异或运算的结果；
<<, >>:返回把一个bitset左移，右移若干位的结果.（补零）；

==，！=：比较两个位数相同的bitset代表的二进制数是否相等；

3.[ ]操作符：
s[k] :表示s的第k位，即可取值也可赋值，编号从0开始；

4.count:
s.count() 返回二进制串中有多少个1；

5.any/none
若s所有位都为0，则s.any()返回false，s.none()返回true；
若s至少有一位为1，则s.any()返回true，s.none()返回false；

6.set/rest/flip
s.set()把s所有位变为1；
s.set(k,v)把s的第k位改为v,即s[k]=v；
s.reset()把s的所有位变为0.
s.reset(k)把s的第k位改为0,即s[k]=0；
s.flip()把s所有位取反.即s=~s；
s.flip(k)把s的第k位取反，即s[k]^=1；
————————————————
版权声明：本文为CSDN博主「逐日的少年」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_44872284/article/details/116741628



bitset

------------相当于一个二进制的数组，并且可以直接用01串赋值-----------------
bitset<4>a1;//长度为4，默认以0填充
bitset<8>a2;//长度为8，将12以二进制保存，前面用0补充


string s = "100101";
bitset<10>a3(s);//长度为10，前面用０补充

//实验检测，char在普通环境不能直接赋值给bitset
//要开c++11，针不戳
char s2[] = "10101";
bitset<13>a4(s2);//长度为13，前面用０补充
//所以这玩意noip上不能用……

cout<<a1<<endl;//0000
cout<<a2<<endl;//00001100
cout<<a3<<endl;//0000100101
cout<<a4<<endl;//0000000010101

----------------------如果超出了bitset定义的范围：-----------------------
bitset<2>bitset1(12);//12的二进制为1100（长度为４），但bitset1的size=2，只取后面部分，即00

string s="100101";
bitset<4> bitset2(s);//s的size=6，而bitset的size=4，只取前面部分，即1001

//char s2[]="11101";
//bitset<4> bitset3(s2);//与bitset2同理，只取前面部分，即1110

cout << bitset1 << endl;　　//00
cout << bitset2 << endl;　　//1001
//cout << bitset3 << endl;　　//1110

------------------------------位运算操作---------------------------------
bitset<4> foo (string("1001"));//这种赋值方式就可以直接用，没有限制
bitset<4> bar (string("0011"));
cout << (foo^=bar) << endl;       // 1010 (foo对bar按位异或后赋值给foo)
cout << (foo&=bar) << endl;       // 0010 (按位与后赋值给foo)
cout << (foo|=bar) << endl;       // 0011 (按位或后赋值给foo)
cout << (foo<<=2) << endl;        // 1100 (左移２位，低位补０，有自身赋值)
cout << (foo>>=1) << endl;        // 0110 (右移１位，高位补０，有自身赋值)
cout << (~bar) << endl;           // 1100 (按位取反) 
cout << (bar>>1) << endl;         // 0001 (右移，不赋值)
cout << (foo==bar) << endl;       // （0）false (0110==0011为false)
cout << (foo!=bar) << endl;       // （1）true  (0110!=0011为true)
cout << (foo&bar) << endl;        // 0010 (按位与，不赋值)
cout << (foo|bar) << endl;        // 0111 (按位或，不赋值)
cout << (foo^bar) << endl;		  // 0101 (按位异或，不赋值)

----------------------------单一元素访问和修改----------------------------
bitset<4>a1("1011");//这个赋值方法只能在c++11里用，noip八行

//可以用上面位运算时的方法
bitset<4>a1(string("1011"));

cout<<a1[0]<<endl;//1
cout<<a1[1]<<endl;//1
cout<<a1[2]<<endl;//0
cout<<a1[3]<<endl;//1
//注意！这两种赋值方式都是反序赋值的
//所以输出值为1101；
//可以直接输出a1来输出正序

//bitset支持单点修改
a1[0]=0;
cout<<a1[0]<<endl;//0
cout<<a1<<endl;//0101

-----------------------------------各种函数------------------------------
bitset<8>foo(string("10011011"));

cout<<foo.count()<<endl;//5　　（count函数用来求bitset中1的位数，foo中共有５个１
cout<<foo.size()<<endl;//8　　（size函数用来求bitset的大小，一共有８位

cout<<foo.test(0)<<endl;//true　　（test函数用来查下标处的元素是０还是１，并返回false或true，此处foo[0]为１，返回true
cout<<foo.test(2)<<endl;//false　　（同理，foo[2]为０，返回false

cout<<foo.any()<<endl;//true　　（any函数检查bitset中是否有１
cout<<foo.none()<<endl;//false　　（none函数检查bitset中是否没有１
cout<<foo.all()<<endl;//false　　（all函数检查bitset中是全部为１

这么多应该就够用了，
————————————————
版权声明：本文为CSDN博主「彗星七号」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/TopTom1234/article/details/108472174
