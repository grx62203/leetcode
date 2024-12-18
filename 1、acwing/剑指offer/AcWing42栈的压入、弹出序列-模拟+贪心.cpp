/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列 1,2,3,4,5 是某栈的压入顺序，序列 4,5,3,2,1 是该压栈序列对应的一个弹出序列，但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。

注意：若两个序列长度不等则视为并不是一个栈的压入、弹出序列。若两个序列都为空，则视为是一个栈的压入、弹出序列。

数据范围
序列长度 [0,1000]。
*/
//时间：n
//弹出顺序不一定，可能边压入，边弹出，找的时候每次将能对的上的都弹出
class Solution {
public:
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size()) return false;
        stack<int> s;
        int popId=0;

        for(int pushId=0; pushId < pushV.size();++pushId){
            s.push(pushV[pushId]);
            while(!s.empty() && s.top()==popV[popId]){
                s.pop();
                ++popId;
            }
        }

        if(s.empty()) return true;
        return false;
    }
};

