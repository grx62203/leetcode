/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。

请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

数据范围
二维数组中元素个数范围 [0,1000]
*/
/*
时间复杂度:n*lgn
*/

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {

        int n = array.size();
        for(int i=0;i<n;i++){
            vector alls(array[i]);
            if(alls.size()==0) return false;
            int l = 0;
            int r = alls.size()-1;

            while(l<r){
                int mid = (l + r)/2;
                if(alls[mid]>=target) r = mid;
                else l = mid + 1;
            }

            if(alls[l] == target) return true;
        }
        return false;
    }
};

/*
时间复杂度:lgn*lgn
*/
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.size() == 0) return false;

        //m为行，n为列
        int m = array.size(),n = array[0].size();

        // cout << n << ' ' << m << endl;
        //找到最后一个<=target的列
        int l = 0,r = n - 1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(array[0][mid] <= target) l = mid;//？符号的表示
            else r = mid - 1;
        }
        // cout << l << endl;
        if(array[0][l] == target) return true;//等于就直接结束
        //找到列，最后一个<=target的行
        int lm = 0,rm = m - 1;
        while(lm < rm)
        {
            int mid = lm + rm + 1 >> 1;
            if(array[mid][l] <= target) lm = mid;
            else rm = mid - 1;
        }
        if(array[lm][l] == target) return true;

        return false;
    }
};
