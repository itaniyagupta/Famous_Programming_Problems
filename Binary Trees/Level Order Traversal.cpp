/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 // Iterative
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
          if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> temp;
        temp.push(root);
        
        while(temp.size() != 0)
        {
            vector<int> res1;
             int s =temp.size();
               
            for(int i=0;i<s;i++)
            {
                TreeNode* front = temp.front();
                res1.push_back(front->val);
                temp.pop();
                
                if(front->left!=NULL){
                    temp.push(front->left);
                }
                if(front->right!=NULL){
                    temp.push(front->right);
                }
            }
            
            res.push_back(res1);
        }
        return res;
        
    }
};

// Recursive Depth-First Search(DFS) Approach

class Solution {
public:
    vector<vector<int>>ans;
	
    void levelord1(TreeNode *root, int level) {
        if (root == NULL) 
		{
			return;
		}
        if(level==ans.size())
		{
			ans.push_back(vector<int> ());
		}
        ans[level].push_back(root->val);
        levelord1(root->left, level+1);
        levelord1(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       levelord1(root,0);
        return ans;
    }
};