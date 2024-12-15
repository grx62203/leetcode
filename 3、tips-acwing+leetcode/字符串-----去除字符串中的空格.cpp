//去掉首尾空格
void trim(string &s)
 {
  
     if( !s.empty() )
     {
         s.erase(0,s.find_first_not_of(" "));
         s.erase(s.find_last_not_of(" ") + 1);
     }
  
 }
 
//去掉所有空格
void trim(string &s)
{
    /*
    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
    */
    int index = 0;
    if( !s.empty())
    {
        while( (index = s.find(' ',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }
 
}
//去除多余空格
/* 思路就是定义两个指针next和tail，一个在前面寻找非空格的字符，另外一个在后面一步一步移动，把后面的字符全部转移到前面来；然后为了去除多余的空格，也就是有多个或者一个空格的地方要留一个空格。*/
#include <iostream>
using namespace std;
 
char * deleteSpace(char * str){
    char * tail = str;
    char * next = str;
 
    while(*next){ // 两个if可以合并到一块儿，这样写只是为了看着方便
        if(*next != ' '){ // 查找不是空格的字符
            *tail = *next;
            tail++;
        }
        if(*next == ' ' && *(next-1) != ' '){ // 只留一个空格的判断条件；当前字符为空格且前一个不为空格。
            *tail = *next;
            tail++;
        }
        next++;
    }
    *tail='\0'; // 字符串结束
    return str;
}
 
int main(){
 
    char str[] = "i   am     a    student.";
    char *res = deleteSpace(str);
    cout << res << endl;
 
    return 0;
}