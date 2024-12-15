- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

//组合问题：
17.电话号码的字母组合
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
77.组合
    给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合
39.组合总和
    给定一个 无重复元素 的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的数字可以 无限制重复被选取 。
40.组合总和II
    给定一个数组 candidates （ 数组中的数字可能重复）和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中 只能使用一次。
216.组合总和III
    找出所有相加之和为n的k个数的组合。组合中只允许含有1-9的正整数，并且每种组合中不存在重复的数字。
377.组合总和Ⅳ
    给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

//切割问题：
93.复原IP地址
131.分割回文串
    给定一个字符串 s，将 s 划分成若干部分，使得每一部分都是回文串。

//子集问题：
78.子集
    给定一组 不含重复元素 的整数数组nums，返回该数组所有可能的子集（幂集）。
90.子集II
    给定一个 可能包含重复元素的整数数组nums，返回该数组所有可能的子集（幂集）。

//序列问题：
491.递增子序列
46.全排列
47.全排列 II
60.排列序列
332.重新安排行程
784.字母大小写全排列

//棋盘问题：
51.N皇后
37.解数独

//单词搜索：
79.单词搜索
212.单词搜索II

1214-93


----------------------------------------------------------------------------
--------------------------组合总结-------------------------------------------
 无重复元素可复选
	1、选取当前元素的个数来分支（选取了0个第一个元素、选取了1个第一个元素、、、、选取的第一个元素刚好小于等于target）
	2、从前到后去除的选取某个元素来分支-剪枝（选取了第一个元素，去除第一个元素选取了第二个元素、去除了前两个元素选取了第三个元素、、、、、）
	3、这一次是否选取当前元素来分支（这一次不选取第一个元素、这一次选取了第一个元素），就算这一次选取了第一个，下一次依旧可以选择
 有重复元素不可复选
	1、先求元素个数、选取当前元素的个数来分支（选取了0个第一个元素、选取了1个第一个元素、、、、选取的第一个元素刚好小于等于target且数量合理）
	2、选取且当前层去除下一层去除某个元素来分支-剪枝再剪枝（选取且当前层与下一层剔除第一个元素，选取且当前层与下一层剔除第二个元素、选取且当前层与下一层剔除第三个元素、、、、、）
	3、这一次是否选取当前元素来分支-不选找到下一个不同-选则去除（这一次不选取第一个元素、这一次选取了第一个元素），就算这一次选取了第一个，下一次依旧可以选择
--------------------------序列总结-------------------------------------------
 无重复元素
	1、（枚举每个位置放不同的数字）
	选取当前位置放不同的数字作分支（数字1、数字二、数字三、、、、）
	2、（枚举每个数字放在不同的位置）（不能保证字典序）
	选取当前数字放在不同的位置作分支（位置1、位置2、位置3、、、、）
 有重复元素
	1、（枚举每个位置放不同的数字）
	选取当前位置放不同的数字作分支（数字1、数字二、数字三、、、、）
	枚举的当前位置不选择相同元素，跳过
	2、（枚举每个数字放在不同的位置）（不能保证字典序）
	选取当前数字放在不同的位置作分支（位置1、位置2、位置3、、、、）
	枚举的当前数字只放在相同元素的下一个位置开始的剩余位置
--------------------------17.电话号码的字母组合+不需要恢复现场-----------------
    void dfs(string& digits, int u, string path) {
        if (u == digits.size()) ans.push_back(path);//每一次走到头，记录一次组合。
        else {
            for (auto c : strs[digits[u] - '0'])
                dfs(digits, u + 1, path + c);
        }
    }
--------------------------77.组合+无重复元素不可复选+位置找数字+以还能挑选的数字为分支
	void dfs(int n, int k, int start) {
        if (!k) {
            ans.push_back(path);
            return;
        }//每一次走到头，记录一次组合。
        for (int i = start; i <= n; i ++ ) {
            path.push_back(i);
            //只是进入下一个，用k计数，用i往后更新了start是位置，意思是组合而不是排列，有了12就不要21了
            dfs(n, k - 1, i + 1);
            path.pop_back();//path在参数外变化，需要回溯恢复现场
        }
    }
--------------------------39.组合总和+无重复元素可复选+选取当前元素个数来分支+每个for结束恢复现场
 求组合结果、限定了必须是和为n，数量无所谓
    //数组c、第u个元素、目标和
	void dfs(vector<int>& c, int u, int target) {
        if (target == 0)  //说明已经凑够了target
        {
            ans.push_back(path);
            return;
        }
        if (u == c.size()) return; //枚举完了数，还没有凑够，无解

        //每一次for都要往下走一次，返回一次 ，返回若干次，这次dfs就结束了
        for (int i = 0; c[u] * i <= target; i ++ ) {
            dfs(c, u + 1, target - c[u] * i); //进入下一个枚举，代表当前数字选了，有可能选0、1、2、3、、、、
            //当i为0的时候，表示这个数字不用取，如果先push的话，表示这个数被取了一次，在进入下一层
            path.push_back(c[u]);             //每枚举一次，都要将当前数字添加到方案里面
        }

        //恢复现场，此时选取第二个元素的所有重复for都是选取某个第一个元素的分支，所以需要所有for结束后恢复现场，再对选取下一数量的第一个元素进行dfs
        for (int i = 0; c[u] * i <= target; i ++ ) {
            path.pop_back();
        }
    }
--------------------------40.组合总和II+有重复元素不可复选+排序+先求元素个数、选取当前元素的个数来分支+每个for结束恢复现场
 求组合结果、限定了必须是和为n，数量无所谓，对于重复元素需要先排序再跳到下一个不重复数字的位置，对于不可复选需要限制当前元素的个数上限
    // 先排序，然后dfs（c，0，c.end()）
    //数组c、第u个元素、目标和
    void dfs(vector<int>& c, int u, int target) {
        //已经找到方案了
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        //找到了所有数
        if (u == c.size()) return;

        //当前数（u）的个数是 cnt 个
        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) k ++ ;
        int cnt = k - u;

        //开始循环当前重复数，保证个数上限、不超target，第一次选0个，第二次选1个
        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            dfs(c, k, target - c[u] * i);//k是下一个不重复数字的位置
            //当i为0的时候，表示这个数字不用取，如果先push的话，表示这个数被取了一次，在进入下一层
            path.push_back(c[u]);
        }

        //还原现场，插进去几个就要删除几个
        for (int i = 0; c[u] * i <= target && i <= cnt; i ++ ) {
            path.pop_back();
        }
    }
--------------------------216.组合总和III+无重复元素不可复选+位置找数字+以还能挑选的数字为分支+每个for之内恢复现场
 求组合结果、限定了必须是k个数之和为n，只使用1-9，从1到9遍历k个
	// dfs（k,n,1）
    //还能选取k个数、总和还能选n、要选取的数（1-9）
    void dfs(int k, int n, int start)
    {
        if (!k)
        {
            if (!n) ans.push_back(path);
            return;
        }
        // 如果i > 10 - k，那么当前方案无论如何都无法选够k个数了。
        for (int i = start; i <= 10 - k; i ++ )//10-k代表着后续还得选，不是非得枚举到9
            if (n >= i)
            {
                path.push_back(i);
                dfs(k - 1, n - i, i + 1);
                path.pop_back();
            }
    }
--------------------------377.组合总和Ⅳ+无重复元素可复选+等同求序列和的个数+动态规划-
 求序列数量、限定和为m的组合的个数而不是需要组合内容，且顺序不同视为不同，可看作需要序列
	int combinationSum4(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> f(m + 1);
        f[0] = 1;
        for (int j = 0; j <= m; j ++ )//遍历和
            for (auto v: nums)        //可复选地遍历元素,121和112的情况都考虑了
                if (j >= v)           
                    f[j] = (f[j] + f[j - v]) % INT_MAX;
        return f[m];
    }
--------------------------93.复原IP地址+分割条件+变参数不需要恢复现场-----------
	//s表示原字符串, u表示枚举到的字符串下标，k表示当前截断的IP个数
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();//最后会多一个 "."，需要弹出
                ans.push_back(path);
            }
            return;
        }
        if (k == 4) return;//提前四段了，无效
        for (int i = u, t = 0; i < s.size(); i ++ ) {
            if (i > u && s[u] == '0') break;  // 新的截断字符大于1个 且 新的截断第一个字符是0 == 超过两个字符且有前导0则break
            t = t * 10 + s[i] - '0';          // 累计前面到现在的和，如果累计数目多了，会超过255break的
            if (t <= 255) dfs(s, i + 1, k + 1, path + to_string(t) + '.');//变参数=不需要回溯
            else break;
        }
    }
--------------------------131.分割回文串+分割条件+当前保留串是回文则分支、不是回文则默认dfs
    //now是新字符串、u是字符串s的位置、s是原字符串
	void dfs(string now, int u, string &s)
    {
        if (u == s.size())//最后一个保留串now，也得判断是否是回文才能判断是否添加方案
        {
            if (check(now))
            {
                path.push_back(now);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }

        if (check(now))
        {
            path.push_back(now);
            dfs("", u, s);//保存当前回文串now、清空保留串now，是为分支一
            path.pop_back();
        }

        dfs(now + s[u], u + 1, s);//不保存当前回文串、不清空保留串且更新now，是为分支二。。。也是不回文的唯一下一步，即添加字符到now更新now
    }
--------------------------131.分割回文串+分割条件+预处理+判断任意子串是否回文+动态规划
 预处理，得[i,j]区间子串是否是回文串
		vector<vector<bool>> f = vector<vector<bool>>(n, vector<bool>(n));
        for (int j = 0; j < n; j ++ )
            for (int i = 0; i <= j; i ++ )
                if (i == j) f[i][j] = true;
                else if (s[i] == s[j]) {
                    //中间没有东西 || 中间的边界相等
                    if (i + 1 > j - 1 || f[i + 1][j - 1]) f[i][j] = true;
                }
--------------------------78.子集+无重复元素不可复选+以选与不选当前数字为分支+每次选取元素后恢复现场以便不选分支
 所有子集
    void dfs(int cur, vector<int>& nums) {
    	//cur就是个计数，只要走完数组，就输出一个子集
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);//选1个
        t.pop_back();
        dfs(cur + 1, nums);//选0个
    }
--------------------------90.子集II+有重复元素不可复选+排序+先求元素个数、选取当前元素的个数来分支+每个for结束批量恢复现场
 所有子集
    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.push_back(path);
            return;
        }
        int k = u + 1;
        while (k < nums.size() && nums[k] == nums[u]) k ++ ;
        for (int i = 0; i <= k - u; i ++ ) {
            dfs(nums, k);
            path.push_back(nums[u]);
        }
        for (int i = 0; i <= k - u; i ++ ) {
            path.pop_back();
        }
    }
--------------------------491.递增子序列+有重复元素+位置找数字+set去重+以还能挑选的数字为分支
 相同数字需要去重，比如ab1b2c，从a进去，可以选b1再从b1进去选c为abc，也可以选b2再从b2进去选c为abc（拒绝从a进入b2去重）
     void dfs(vector<int>& nums, int start) {
        if (path.size() >= 2) ans.push_back(path);
        if (start == nums.size()) return;
        unordered_set<int> S;
        for (int i = start; i < nums.size(); i ++ )
            if (path.empty() || nums[i] >= path.back()) {
                if (S.count(nums[i])) continue;//去重b2的情况
                S.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
    }
--------------------------46.全排列+无重复元素+枚举每个位置放不同的数字----------
    void dfs(vector<int>& nums, int u) {                             //u表示枚举到了方案数组path的哪个位置
        if (u == nums.size()) {//所有的数字已使用
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {//遍历每一个数字       //枚举当前位置可以选择哪些数
            if (st[i] == false) {//该数字没有使用过
                st[i] = true;                                         //标记选过
                path[u] = nums[i];                                    //将未使用过的数字放到指定位置
                dfs(nums, u + 1);                                     //继续下一个位置
                st[i] = false;                                        //恢复现场
                //path 不用恢复，下一次for会覆盖。
            }
        }
    }
--------------------------46.全排列+无重复元素+枚举每个数字放不同的位置----------
    void dfs(vector<int>& nums, int u) {                             //u表示枚举到了方案数组path的哪个备用数
        if (u == nums.size()) {//所有的位置已使用
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ ) {//遍历每一个位置       //枚举当前数u可以选择哪些数
            if (st[i] == false) {//该位置没有使用过
                st[i] = true;                                         //标记选过
                path[i] = nums[u];                                    //将当前指定数字放到未选过的位置
                dfs(nums, u + 1);                                     //继续下一个数字
                st[i] = false;                                        //恢复现场
                //path 不用恢复，下一次for会覆盖。
            }
        }
    }
--------------------------47.全排列II+有重复元素+排序+枚举每个位置放不同的数字+跳过相同数字
 连续的几个重复的数字，每次只选择第一个没有使用过的，即依次选重复数字
    void dfs(vector<int>&nums, int u) {
        if (u == nums.size()) {// 所有的位置都已使用
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i ++ ) {//遍历每一个数字       //枚举当前位置可以选择哪些数
            if (!st[i]) {//该数字没有使用过
                if (i && nums[i - 1] == nums[i] && !st[i - 1]) continue;//连续的几个重复的数字，每次只选择第一个没有使用过的，即依次选重复数字
                st[i] = true;                                        //标记选过
                path[u] = nums[i];                                   //将未使用过的数字放到指定位置
                dfs(nums, u + 1);                                    //继续下一个位置
                st[i] = false;                                       //恢复现场
                //path 不用恢复，下一次for会覆盖。
            }
        }
    }
--------------------------47.全排列II+有重复元素+排序+枚举每个数字放不同的位置+相同数字则从当前位置的下一位置开始
 相同数后面的只能从上一数选择位置的后一个位置开始
    void dfs(vector<int>& nums, int u, int start)
    {
        if (u == nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i ++) //遍历每一个位置       //枚举当前数可以放在哪些位置
        {
            if (!st[i]){ //该位置没有放数
                st[i] = true;                                           //标记选过
                path[i] = nums[u];                                      //将当前指定数字放到未选过的位置
                int next = u + 1 < nums.size() && nums[u + 1] == nums[u] ? i + 1 : 0;//相同数后面的只能从上一数选择位置的后一个位置开始
                dfs(nums, u + 1, next);                                  //继续下一个数，如果i+1=i则指定下一个位置开始
                st[i] = false;                                           //恢复现场
                //path 不用恢复，下一次for会覆盖。
            }
        }
    }
--------------------------60、排列序列+无重复元素+位置找数字+枚举每个位置放不同的数字+后续全排列数目小于k则跳过
 相当于验证每一个当前位置对应数分支的对应全排列数目是否能满足k，能的话表示选择这个数，进去再DFS求下一个位置
    vector<int>factorial{ 1,1,2,6,24,120,720,5040,40320,362880 }; //阶乘字典
    void backtrack(vector<int>&nums, int i, int& k) {	//k:距离目标还剩几个 
        if (i == nums.size())                           //如果结束的时候正好到了第k个
            if (k-- == 0)  return;
        //每次进来选取得都是最小的数，比如选定1，看后面全排列数量与k的大小关系
        for (int j = i; j < nums.size(); j++) {
            if (k > factorial[nums.size() - i - 1]) {	//若12之后第三个选择了3，若选3之后的全排列数量不足k，那么就不能选3，没有这条路
                k -= factorial[nums.size() - i - 1];
                continue;
            }
            vector<int> tmp(nums);
            int jj = j;
            while (jj > i) { swap(nums[jj], nums[jj - 1]); jj--; }//交换，使第i个位置选择了jj
            backtrack(nums, i + 1, k);
            if (k == 0) return;
            nums = tmp;	//回溯(恢复），从下一个可选数字分支进去
        }
    }
    string getPermutation(int n, int k) {
        string ans;
        vector<int>ivec;
        for (int i = 1; i <= n; i++) ivec.push_back(i);
        int x = 0;
        backtrack(ivec, 0, k);
        for (int i = 0; i < ivec.size(); i++) ans.push_back(ivec[i] + '0');
        return ans;
    }
--------------------------332.重新安排行程+有向图欧拉路径+贪心+优先遍历字典序最小+出边遍历结束选加入路径
 /*
    经典的有限图欧拉路径（一笔画）问题：找到一条路径，遍历所有边，点在路径中可以重复，边不可以重复。
    直接从起点开始dfs即可，每次选择一条没有遍历过的边，递归进行遍历。
    当把当前节点的所有出边都遍历完时，将该点加入路径序列。
    最终记录的路径是真正遍历路径的逆序，所以我们要将记录的路径逆序输出。
    题目中要求我们输出字典序最小的路径，直接贪心即可，每次优先选择字典序最小的出边进行遍历。这一步可以用堆或者平衡树来存储每个点的所有出边，在C++中可以用 priority_queue 或者 multiset。
    时间复杂度分析：每条边只遍历一次，但需要对每个点的所有出边按字典序排序，所以总时间复杂度是 O(nlogn)
 */
    unordered_map<string, multiset<string>> g;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //整理航线。即入点与出点
        for (auto& e: tickets) g[e[0]].insert(e[1]);
        //从JFK开始出发
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    //从a直接去找字典序最小的出边点，然后会返回来到a然后dfs第二个出边点，这个更快，比a直接找到第二个点更快，
    //所以当erase之后，就没有a直接找到第二个点这个dfs了，这也是肯定可以有一个完整航线的题目背景下才有的
    void dfs(string u) {
        while (g[u].size()) {
            auto ver = *g[u].begin();//找到当前点所有出边的最小字典序出边点
            g[u].erase(g[u].begin());
            dfs(ver);
        }
        ans.push_back(u);//遍历完当前点的出边才加入路径，所以倒序
    }
--------------------------784.字母大小写全排列+以字母不变与字母变换为分支+数字则默认dfs
 /*
     给定一个字符串S，我们可以将其中的大写字母换成小写字母，或将小写字母换成大写字母，从而得到一个新的字符串。
     深度优先搜索。从左到右一位一位枚举：
     	如果遇到数字，则直接跳过当前位，枚举下一位；
     	如果遇到字母，则分别将当前位设成小写字母和大写字母，然后递归到下一位；
     小技巧：可以用位运算改变当前字母的大小写，从而简化代码：将一个字母异或32，即可改变这个字母的大小写。比如：
     'a' ^ 32 = 'A';
     'B' ^ 32 = 'b';
 */
	void dfs(string &S, int u)
    {
        if (u == S.size())
        {
            ans.push_back(S);
            return;
        }
        dfs(S, u + 1);
        if (S[u] >= 'A')
        {
            S[u] ^= 32;
            dfs(S, u + 1);
        }
    }
--------------------------51.N皇后+以当前行的所有位置为分支+条件判断跳过---------
    void dfs(int u){
        if(u == n){
            ans.push_back(path);
            return;
        }
        //遍历当前行所有位置，如果有空，填进去算一条路，跳到下一行选择
        for(int i = 0; i < n; i ++){
            if(!col[i] && !dg[u-i+n] && !udg[u+i]){
                path[u][i] = 'Q';
                col[i] = dg[u-i+n] = udg[u+i] = true;
                dfs(u+1);
                path[u][i] = '.';
                col[i] = dg[u-i+n] = udg[u+i] = false;
            }
        }
    }
--------------------------37.解数独+按行遍历+枚举每个位置放不同的数字+数组判别跳过+返回合法性
 class Solution {
 public:
    bool row[9][9], col[9][9], cell[3][3][9];
    //每一行、每一列、每一个小九宫格  的每一位（有重复）  都要有一个数组来记录若干数字的可行性
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);
        //遍历，更新数组
        for (int i = 0; i < 9; i ++ )
            for (int j = 0; j < 9; j ++ )
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                    //ceil  上取整
                }
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int x, int y) {
        //按行遍历每一个
        if (y == 9) x ++, y = 0;
        if (x == 9) return true;
        //当前位置有数了，跳到下一个位置
        if (board[x][y] != '.') return dfs(board, x, y + 1);
        //遍历这个位置可能填的数字
        for (int i = 0; i < 9; i ++ )
        	//第x行，第y列，第m都没有出现过  i 这个数字，将 i 填入 ，调到下一个位置，如果不选择的话恢复现场
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i])
            {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                //如果下一个不是ture ，恢复一下现场，找当前位置 填入 下一个 数
                if (dfs(board, x, y + 1)) return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
            }
        return false;
    }
 };
--------------------------79.单词搜索+从每一个位置开始搜索+以四个方向为分支+边界墙判别跳过+返回合法性
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        //某个字母不符，则这条线不行，层层返回fasle，只有四个方向都false，这个位置才false
        if (board[x][y] != word[u]) return false;
        //如果能走到最后且最后一个字母一样，说明找到了
        if (u == word.size() - 1) return true;
        char t = board[x][y];
        //避免重复被使用
        board[x][y] = '.';
        //dfs四个方向
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            //跳过，不进行dfs
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            //层次返回当前方向是否存在，只有有一个方向返回真，这个位置就是真
            if (dfs(board, word, u + 1, a, b)) return true;
        }
        //到这里了，说明这个位置的四个方向都失败了，需要还原现场，以防以后再使用
        board[x][y] = t;
        return false;
    }
--------------------------212.单词搜索II+前缀树--------------------------------
 //基本思想是暴力搜索出所有单词路径，再判断该路径表示的单词是否出现在单词列表中。枚举所有路径时先枚举起点，再枚举路径延伸的方向。
 //但朴素DFS搜索空间太大，直接搜会超时。所以我们需要剪枝。
 //我们先将所有单词存入Trie树中，这样我们在搜索时，如果发现当前单词前缀不在trie中，那么当前的路径一定不会构成任意一个单词，我们直接return。
 class Solution {
     struct Node
    {
        int id;
        Node *next[26];
        Node()
        {
            id = -1;
            for (int i = 0; i < 26; i ++ )
                next[i] = 0;
        }
    };
    Node *root;
    void insert(string word, int id) {
        Node *p = root;
        for (char c : word)
        {
            int son = c - 'a';
            if (!p->next[son]) p->next[son] = new Node();
            p = p->next[son];
        }
        p->id = id;
    }
    unordered_set<string> hash;
    vector<string> ans;
    vector<vector<bool>> st;
    vector<string> _words;
    int n, m;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return ans;
        _words = words;
        root = new Node();
        for (int i = 0; i < words.size(); i ++ ) insert(words[i], i);
        n = board.size(), m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                dfs(board, i, j, root->next[board[i][j]-'a']);
        return ans;
    }
    void dfs(vector<vector<char>>& board, int x, int y, Node *u)
    {
        if (!u) return;
        st[x][y] = true;
        if (u->id != -1)
        {
            string match = _words[u->id];
            if (!hash.count(match))
            {
                hash.insert(match);
                ans.push_back(match);
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b])
            {
                char c = board[a][b];
                dfs(board, a, b, u->next[c-'a']);
            }
        }
        st[x][y] = false;
    }
 };