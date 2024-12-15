

----------------------------------------------------------------------------
--------------------------长------------------------------------------------


1、保证x-t与x+t不越界
// 防止 x 过小，x-t 小于 INT_MIN，这样会溢出。
// 若 x>=INT_MIN+t，则 x-t>=INT_MIN，不会溢出；若 x<INT_MIN+t，取max的话，最后值为INT_MIN+t-t=INT_MIN不会溢出
max(x,INT_MIN+t)-t;

// 防止 x 过大，x+t 大于 INT_MAX，这样会溢出。
// 若 x<=INT_MAX-t，则 x+t <=INT_MAX，不会溢出；若 x>INT_MAX-t，去min后，最后只为INT_MAX-t+t=INT_MAX不会溢出
min(x,INT_MAX-t)+t;



2、字符串与整数转换越界问题
int
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

long long
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


3、