// Problem statement Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
      int i; 
      int starCurr = 0;
      int currlen;
      int maxlen = 0;
      int startmaxlen;
    
        if (s.length() == 0){
            return 0;
        }
 
     unordered_map<char, int> pos;
     pos[s[0]] = 0;
 
    for (i = 1; i < s.length(); i++) {
 
        if (pos.find(s[i]) == pos.end())
            pos[s[i]] = i;
 
        else {
            if (pos[s[i]] >= starCurr) {
 
                currlen = i - starCurr;
                if (maxlen < currlen) {
                    maxlen = currlen;
                    startmaxlen = starCurr;
                }
                starCurr = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
        }
    }
 
    if (maxlen < i - starCurr) {
        maxlen = i - starCurr;
        startmaxlen = starCurr;
    }
    return maxlen;  
    }
};