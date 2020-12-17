// Problem Statement Link - https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length();
        
        if(s.length()==0) 
            return true;
        
        while(i<j)
        {
            if (!isalnum(s[j])) 
            { 
                j--; 
                continue; 
            }
            
            if (!isalnum(s[i])) 
            { 
                i++; 
                continue; 
            }
            
            if (tolower(s[i++]) != tolower(s[j--])) 
                return false;
        }
        return true;
    }
};