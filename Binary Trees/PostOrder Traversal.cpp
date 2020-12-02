// Problem Statement Link - https://leetcode.com/problems/binary-tree-postorder-traversal/


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

// Recursive
// Time : O(n) 
class Solution {
 public:
    void postord1(TreeNode* root,vector<int>&res)
    {
        if(root == NULL){
        return;
        }
        
          postord1(root->left, res); 
          postord1(root->right, res);
          res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
 
        postord1(root, res);
        return res;  
    }
};

// Iterative

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
		vector<int> ans;
        
		if(root==NULL) 
		{
			return ans;
		}
        stack<TreeNode*> p;
        p.push(root);
		
        while(!p.empty()){
            
			TreeNode* node =p.top();
            p.pop();
            
            if(node ==NULL)
			{
                break;
            }
            
			ans.push_back(node->val);
            if(node->left  != NULL)
			{
                p.push(node->left);
            }
            if(node->right  != NULL){
                p.push(node->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

