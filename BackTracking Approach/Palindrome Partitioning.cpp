// Problem Statement Link - https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
   bool ispalin(string s)
   {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
   }
    void palin(string s,vector<string> &v,vector<vector<string>> &res)
    {
        if(s.length()==0)
        {
            res.push_back(v);
            return ;
        }
        for(int i=0;i<s.length();i++)
        {
            if(ispalin(s.substr(0,i+1)))
            {
                v.push_back(s.substr(0,i+1));
                palin(s.substr(i+1),v,res);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> v;
        palin(s,v,res);
    return res;
    }
};