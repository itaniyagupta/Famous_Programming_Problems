// Problem Statement Link - https://leetcode.com/problems/longest-common-prefix/

// Using sorting
// Time : O(m n log n) where n-> size of array of strings; m -> length of largest string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if (n == 0) 
        return ""; 
  
       if (n == 1) 
        return strs[0]; 
  
        sort(strs.begin(), strs.end()); 

        int len = min(strs[0].size(), strs[n - 1].size()); 

        string first = strs[0], last = strs[n - 1]; 
        int i = 0; 
        while (i < len && first[i] == last[i]) 
            i++; 

        string pre = first.substr(0, i); 
        return pre;
    }
};

// Word by Word Matching
// Time : O(n*m), Space : O(m) where n-> size of array of strings; m -> length of largest string

class Solution {
public:
    string helper(string str1, string str2) 
    { 
        string result; 
        int n1 = str1.length(), n2 = str2.length(); 

        for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
        { 
            if (str1[i] != str2[j]) 
                break; 
            result.push_back(str1[i]); 
        } 

        return (result); 
    }
    
    string longestCommonPrefix(vector<string>& strs) { 
        
        int n = strs.size();
        string prefix =  strs[0]; 
        for (int i=1; i<=n-1; i++) 
            prefix = helper(prefix, strs[i]); 

        return (prefix); 
    }
    
};

// Character by Character Matching
// Time : O(n*m), Space : O(m) where n-> size of array of strings; m -> length of largest string

class Solution {
public:
    int minlen(vector<string>& strs, int n) 
    { 
        int min = strs[0].length(); 

        for (int i=1; i<n; i++) 
            if (strs[i].length() < min) 
                min = strs[i].length(); 

        return(min); 
   } 
   string longestCommonPrefix(vector<string>& strs) { 
        
        int n = strs.size();
        int minlen = minlen(strs, n); 
  
        string result;
        char current; 
  
        for (int i=0; i<minlen; i++) 
        { 
            current = strs[0][i]; 
  
            for (int j=1 ; j<n; j++) 
                if (strs[j][i] != current) 
                    return result; 

        result.push_back(current); 
        } 
  
    return (result);  
    }
    
};


// Divide & Conquer Algoritm
// Time : O(n*m), Space:  O(m log n) where n-> size of array of strings; m -> length of largest string

class Solution {
public:
    string helper(string str1, string str2) 
    { 
        string result; 
        int n1 = str1.length(), n2 = str2.length(); 

        for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
        { 
            if (str1[i] != str2[j]) 
                break; 
            result.push_back(str1[i]); 
        } 
        return (result); 
    }
    string commonPrefix(vector<string>& strs, int low, int high) 
    { 
        string ans;
        if (low == high) 
           ans = strs[low]; 

        if (high > low) 
        {
            int mid = low + (high - low) / 2; 

            string str1 = commonPrefix(strs, low, mid); 
            string str2 = commonPrefix(strs, mid+1, high); 

            ans = helper(str1, str2); 
        } 
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs){
        
        int n = strs.size();
        string ans = commonPrefix(strs, 0, n-1);
    
        return ans;
    }
};



