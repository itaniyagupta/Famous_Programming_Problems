// Problem statement link - https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
          return "1";  
        }
                        
        string ans, prev;
        int count;
        prev = countAndSay(n - 1);
        for (int i = 0; i < prev.length(); i++)
        {
            count++;
            while (prev[i] == prev[i + 1])
            {
                i++;
                count++;
            }
            ans += to_string(count) + prev[i];
            count=0;
        }
        return ans;
        
    }
};