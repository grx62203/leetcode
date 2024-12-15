/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 `Solution` class:

- `Solution(int[] nums)` 使用整数数组 `nums` 初始化对象
- `int[] reset()` 重设数组到它的初始状态并返回
- `int[] shuffle()` 返回数组随机打乱后的结果
*/
//算法伪码：

given an array a of n elements:
for i from 0 to n - 1
	random integer j with i <= j <= n - 1
	exchange a[i] and a[j]
end


//C/C++中在区间[a,b]生成随机数（都是整数）的方法是这样的：

a + std::rand() % ( b - a + 1 )
这里补充一点：std::rand()不保证线程安全，之前试过在多个线程使用rand函数，记得好像是每个线程都产生了相同的随机序列。如果是多线程环境，推荐使用C++11的随机数生成方法（每个线程保存一个独立的生成器对象，这样就互不干扰）。

class Solution 
{
	struct Initializer
	{
		Initializer()	{
			std::srand( std::time( nullptr ) ); 
		}
	};
	inline static Initializer	m_Init{};	// 程序启动时初始化随机数生成器

public:
	Solution( const vector< int > &nums )
		: m_Origin( nums ), m_Shuffled( nums )	{}

	vector< int > reset() {
		return m_Origin;
	}

	vector< int > shuffle()
	{
		int i{}, n = m_Shuffled.size();
		for( ; i < n; ++i )
		{
			auto r = i + rand() % ( n - i );	// r : [ i, n - 1 ]
			swap( m_Shuffled[ i ], m_Shuffled[ r ] );
		}

		return m_Shuffled;
	}

private:
	vector< int >				m_Origin;
	vector< int >				m_Shuffled;
};