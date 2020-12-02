// Problem Statement Link - https://leetcode.com/problems/reverse-string/

// Time : O(n) ; Space : O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l = 0, r = s.size()-1;
        while(l<r) 
            swap(s[l++], s[r--]);        
    }
};
