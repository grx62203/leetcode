/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

例如输入数组 [3,32,321]，则打印出这 3 个数字能排成的最小数字 321323。

数据范围
数组长度 [0,500]。

样例
输入：[3, 32, 321]

输出：321323
注意：输出数字的格式为字符串。
*/
//leetcode
//冒泡排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len  - 1; i++){
            bool isSort = true;
            for (int j = 0; j < len - 1 - i ; j++){
                string s1 = to_string (nums[j]) + to_string (nums[j + 1]);
                string s2 = to_string (nums[j + 1]) + to_string (nums[j]);
                if (s1 > s2){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    isSort = false;
                }
            }

            if (isSort) break;
        }

        string ret = "";
        for (int i = 0; i < len; i++){
            ret += to_string (nums[i]);
        }
        
        return ret;
    }
};
//选择排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 选择排序
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums){
            ans.push_back(to_string(num));
        }

        for (int i = 0; i < len; i++){
            int minIndex = i;
            for (int j = i + 1; j < len; j++){
                if (ans[minIndex] + ans[j] > ans[j] + ans[minIndex]){
                    minIndex = j;
                }
            }

            string temp = ans[minIndex];
            ans[minIndex] = ans[i];
            ans[i] = temp;
        }

        string ret = "";
        for (auto str : ans){
            ret += str;
        }
        
        return ret;
    }
};
//插入排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 插入排序
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));

        for (int i = 1; i < len; i++){
            for (int j = i; j > 0 && ans[j - 1] + ans[j] > ans[j] + ans[j - 1]; j--){
                string tmp = ans[j - 1];
                ans[j - 1] = ans[j];
                ans[j] = tmp;
            }
        }

        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }
};
//希尔排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 希尔排序
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));

        int h = 1;
        while (h < len / 3) h = 3 * h + 1;

        while (h >= 1){
            for (int i = h; i < len; i++){
                for (int j = i; j >= h && ans[j - h] + ans[j] > ans[j] + ans[j - h]; j -= h){
                    string tmp = ans[j - h];
                    ans[j - h] = ans[j];
                    ans[j] = tmp;
                }
            }
            h /= 3;
        }
        
        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }
};
//归并排序-自顶向下
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 归并排序,自顶向下
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));
        vector<string> tmp(len);
        Sort(ans, tmp, 0, len - 1);
        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }

    void Sort(vector<string>& ans, vector<string> tmp, int left, int right){
        if (right <= left) return;
        int mid = left + (right - left) / 2;
        Sort(ans, tmp, left, mid);
        Sort(ans, tmp, mid + 1, right);
        Merge(ans, tmp, left, mid, right);
    }

    void Merge(vector<string>& ans, vector<string> tmp, int left, int mid, int right){
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++){
            tmp[k] = ans[k];
        }
        for (int k = left; k <= right; k++){
            if (i > mid) ans[k] = tmp[j++];
            else if (j > right) ans[k] = tmp[i++];
            else if (tmp[i] + tmp[j] > tmp[j] + tmp[i]) ans[k] = tmp[j++];
            else ans[k] = tmp[i++];
        }
    }
};
//归并排序-自底向上
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 归并排序,自底向上
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));
        vector<string> tmp(len);

        for (int i = 1; i < len; i = i + i){
            for (int j = 0; j < len - i; j += i + i){
                Merge(ans, tmp, j, j + i - 1, min(j + i + i - 1, len - 1));
            }
        }
        
        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }


    void Merge(vector<string>& ans, vector<string> tmp, int left, int mid, int right){
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++){
            tmp[k] = ans[k];
        }
        for (int k = left; k <= right; k++){
            if (i > mid) ans[k] = tmp[j++];
            else if (j > right) ans[k] = tmp[i++];
            else if (tmp[i] + tmp[j] > tmp[j] + tmp[i]) ans[k] = tmp[j++];
            else ans[k] = tmp[i++];
        }
    }
};
//快速排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 快速排序
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));
        sort(ans, 0, len - 1);
        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }

    void sort(vector<string>& ans, int left, int right){
        if (right <= left) return;
        int j = partition(ans, left, right);
        sort(ans, left, j - 1);
        sort(ans, j + 1, right);
    }
    
    // 切分
    int partition(vector<string>& ans, int left, int right){
        int i = left, j = right;
        string pivot = ans[left];
        while (true){
            while (ans[i] + pivot <= pivot + ans[i]){
                if (++i > j) break;
            }
            while (pivot + ans[j] < ans[j] + pivot){
                if (--j < i) break;
            }
            if (i >= j) break;
            string tmp = ans[i];
            ans[i] = ans[j];
            ans[j] = tmp;
        }
        string tmp = ans[left];
        ans[left] = ans[j];
        ans[j] = tmp;
        return j;
    }
};
//快速排序-三向切分
class Solution {
public:
    string minNumber(vector<int>& nums) {
        // 快速排序-三向切分
        int len = nums.size();
        vector<string> ans;
        for (auto num : nums) ans.push_back(to_string(num));
        sort(ans, 0, len - 1);
        string ret = "";
        for (auto str : ans) ret += str;
        return ret;
    }

    void sort(vector<string>& ans, int left, int right){
        if (right <= left) return;
        int lt = left, i = left + 1, gt = right;
        string tmp = ans[left];
        while(i <= gt){

            if (ans[i] + tmp == tmp + ans[i]){
                i++;
            }
            else if (ans[i] + tmp < tmp + ans[i]){
                exchange(ans, lt++, i++);
            }
            else{
                exchange(ans, i, gt--);
            }
        }

        sort(ans, left, lt - 1);
        sort(ans, gt + 1, right);
    }
    
    // 交换
    void exchange(vector<string>& ans, int exchIndex1, int exchIndex2){
        int len = ans.size();
        if (exchIndex1 >= 0 && exchIndex1 < len && exchIndex2 >= 0 && exchIndex2 < len){
            string tmp = ans[exchIndex1];
            ans[exchIndex1] = ans[exchIndex2];
            ans[exchIndex2] = tmp;
        }
    }
};