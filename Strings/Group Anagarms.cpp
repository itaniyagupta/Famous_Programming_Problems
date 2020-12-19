// Problem statement link - https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> map;
        int n = strs.size();
        string temp;
        
        for(int i=0;i<n;i++){
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end()); 
            map[strs[i]].push_back(temp);
        }
        
        vector<vector<string>> res;
        
        for(auto i=map.begin();i!=map.end();i++){
            res.push_back(i->second); 
        }
    return res;
  } 
};