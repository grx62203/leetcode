/*
给你一根长度为 n 绳子，请把绳子剪成 m 段（m、n 都是整数，2≤n≤58 并且 m≥2）。

每段的绳子的长度记为 k[1]、k[2]、……、k[m]。

k[1]k[2]…k[m] 可能的最大乘积是多少？

例如当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到最大的乘积 18。
*/
//时间 2^n
//空间 n
class Solution {
    int res = 0;
    public int cuttingRope(int n) {
        return recur(n, new HashMap<Integer, Integer>());
    }
    public int recur(int n, HashMap<Integer, Integer> map){
        if(n <= 2) return 1;
        if(map.containsKey(n)) return map.get(n);
        for(int i = 1; i < n; i++){
            res = Math.max(res, Math.max(i * recur(n - i, map), i * (n - i)));
        }
        // 每次得到一个结果时，都需要将结果存储到对应的节点中
        map.put(n, res);
        return res;
    }
};
