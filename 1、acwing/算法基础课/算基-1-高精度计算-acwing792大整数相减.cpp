/*
给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的差。

数据范围
1≤整数长度≤105
*/

/*
大整数相减
加减乘除的统一写法 就是将所有的ABC数组都是低位在前、高位在后
*/
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B)//大整数判断A是否比B大
{
    if (A.size() != B.size()) return A.size() > B.size();//如果位数不同，位数大小比较就是AB数大小比较结果

    for (int i = A.size() - 1; i >= 0; i -- )//从高位开始判断
        if (A[i] != B[i])
            return A[i] > B[i];//两个数的当前位值比较，找到第一位不相等的位，判断位值，A[I]大的话返回A更大

    return true;//如果相等，也返回true
}
//高精度（大整数）相减模板
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;//保存答案
    for (int i = 0, t = 0; i < A.size(); i ++ )//从前往后，也就是从个位（低位）开始计算
    {
        t = A[i] - t;               //先减去借位
        if (i < B.size()) t -= B[i];//再减去B[i]
        C.push_back((t + 10) % 10); //借位或者不借位都考虑在内，借位需要%10，不借位不需要
        if (t < 0) t = 1;           //此时是借位的情况
        else t = 0;                 //此时没有借位，不需要标记 
    }

    //while (C.size() > 1 && C.back() == 0) C.pop_back();//去前导零
    for(int i=C.size()-1;i>=0;i--)
        if(C.back()!=0)break;
        else if(!C.back())C.pop_back();//这里将所有的0都弹出来了
    if(C.size()==0)C.push_back(0);//如果是A-B=0,那么最后一位还需要补上一个o

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;//a 是字符串，下一行会转换为数，减去字符‘0’
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');//反序，从个位（低位）开始输入
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    vector<int> C;
    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << '-';//若B比A大，将A-B变为B-A，先加上负号
    //同步计算后结果也是低位在前，高位在后，需要输出的时候就需要还原成高位在前、低位在后，就倒着输出
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}