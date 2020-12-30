// Problem Statement Link - https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) { 
        stack<int>S;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) 
        {
            S.push(pushed[i]);
            while (!S.empty() && S.top() == popped[j]) 
            {
                S.pop();
                j++;
            }
        }
            if(S.empty())
                return true;
            else
                return false;
    }
};