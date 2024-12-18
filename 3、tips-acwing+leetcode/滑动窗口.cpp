



--------------------------串联所有字符的子串----------------------------------
--------------------------长度最小的子数组------------------------------------




--------------------------串联所有字符的子串----------------------------------
1、单起点固定长度
	双指针维护窗口
    	右窗口
    		一直增加元素、增加hash
    	左窗口
    		判别元素hash值，如果重复==去除元素+减少hash‘
2、多起点固定长度
	for 每一个起点，
		for 以固定长度移动每一个起点开始走的窗口，直到走到末尾
			维护窗口长度
	for (int i = 0; i < w; i ++ )                  //分为w组，每组分别滑动窗口
        {
            unordered_map<string, int> wd;   int cnt = 0;
            for (int j = i; j + w <= n; j += w) {
            	//维护窗口左端
                if (j >= i + m * w)                   //窗口大小超限之后每一次都要删掉一个单词
                {
                    auto word = s.substr(j - m * w, w);//找到前面的单词
                    wd[word] -- ;                      //删掉
                    if (wd[word] < tot[word]) cnt -- ; //如果删掉了有效单词，cnt减去1
                }
                auto word = s.substr(j, w);            //找到下一个单词
                wd[word] ++ ;                          //把下一个单词加进去
                if (wd[word] <= tot[word]) cnt ++ ;    //加进去之后判别是否有效，用cnt标记增长
                if (cnt == m) res.push_back(j - (m - 1) * w);//有效标记达标，输出其实位置
            }
        }



--------------------------长度最小的子数组------------------------------------
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }


