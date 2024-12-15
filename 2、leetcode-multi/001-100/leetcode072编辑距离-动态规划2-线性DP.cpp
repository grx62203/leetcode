/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

#define MIN(a , b , c) (((a) < (b) ? (a) : (b)) < (c) ? ((a) < (b) ? (a) : (b)) : (c))

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1+1][len2+1];
    for(int i = 0; i < len1+1; i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0; i < len2+1; i++)
    {
        dp[0][i] = i;
    }
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = MIN(dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[len1][len2];
}



//内存优化
#define MIN(a , b , c) (((a) < (b) ? (a) : (b)) < (c) ? ((a) < (b) ? (a) : (b)) : (c))

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len2+1];                              //初始化
    for(int i = 0; i < len2+1; i++)  dp[i] = i;  //初始化一维空间
    int s = dp[0];                               //临时变量保存dp【i-1】【j-1】
    for(int i = 0; i < len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            int t = dp[j];//动态更新保存dp[i-1][j-1]
            if(word1[i] == word2[j-1])     dp[j] = s;
            else                           dp[j] = MIN(dp[j] , dp[j-1] , s) + 1;
            s = t;//更新dp[i-1][j-1]
        }
        dp[0]++;
        s = dp[0];
    }
    return dp[len2];
}

