


----------------------------------------------------------------------------
--------------------------字符串转换整数--------------------------------------
1、int
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

2、long long
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