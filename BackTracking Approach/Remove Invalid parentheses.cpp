// Problem Statement Link - https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
        bool isParanthesis(char c){
            return c == '(' || c == ')';
        }
        bool isValid(string s){
            int count = 0;
            for(char &c: s)
            {
                if(c == '(')
                    count++;
                else if(c == ')')
                    count--;
                if(count < 0)
                    return false;
            }
            return count == 0;
        }
      vector<string> removeInvalidParentheses(string s) {
            vector<string> ans;
            if(s.size() == 0)
            {
                return {""};
            }
            unordered_set<string> visited;
            queue<string> q;
            bool level = false;;
            string temp = "";
            q.push(s);
            visited.insert(s);
            while(!q.empty())
            {
                s = q.front();
                q.pop();
                if(isValid(s))
                {
                    cout<<s<<endl;
                    ans.push_back(s);
                    level = true;
                }
                if(level)
                    continue;
                for(int i=0; i<s.size(); i++)
                {
                    if(!isParanthesis(s[i]))
                        continue;

                    temp = s.substr(0,i) + s.substr(i+1); //leaving the ith element
                    if(visited.count(temp) == 0)
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
	        }
	   return ans;
    }
};