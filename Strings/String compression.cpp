//Problem statement link - https://leetcode.com/problems/string-compression/

// Time : O(n)

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 1;
        int num = 1;
        chars.push_back('0');
        
        for(int i = 1; i<chars.size(); i++)
        {
            if(chars[i] == chars[i-1])
            {
                num++;
            }
            else
            {
                if(num > 1)
                {
                    string s = to_string(num);
                    for(int j = 0; j<s.size(); j++)
                    {
                        chars[l++] = s[j];
                    }                    
                }
                chars[l++] = chars[i];
                num = 1;
            }
        }
        return l-1;
    }
};