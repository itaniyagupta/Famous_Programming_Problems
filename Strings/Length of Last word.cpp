// Problem Statement Link - https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n=s.length()-1;
        int l=0;
        while(s[n]==' ' && n>=0)
        {
            n--;
        }
        while(s[n]!=' ' && n>=0)
        {
            l++;
            n--;
        }
        
        return l;
    }
};