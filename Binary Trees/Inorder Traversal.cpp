// Problem Statement Link - https://leetcode.com/problems/binary-tree-inorder-traversal/

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
 
class Solution {
public:
    void inord1(TreeNode* root,vector<int>&res)
    {
        if(root == NULL){
        return;
        }
          
          inord1(root->left, res); 
          res.push_back(root->val);
          inord1(root->right, res);
         
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
 
        inord1(root, res);
        return res;
    }
};

// Iterative

class Solution {
public:
	 vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*>  p;
        vector <int> ans;
        TreeNode* node = root;
        
        while (node || !p.empty()) {
            
            if (node != NULL) 
			{
               p.push(node);
               node = node->left;
            }
            else 
			{
               node = p.top();
               p.pop();
               ans.push_back(node->val);
               node = node->right;    
            }   
        }
        return ans;
	 }
};