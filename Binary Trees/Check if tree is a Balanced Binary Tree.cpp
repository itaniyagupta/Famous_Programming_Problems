// Problem Statement Link - https://leetcode.com/problems/balanced-binary-tree/; https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

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
 
 /*
 
     7   
	/ \
   6   5  
  /	\  / \
 2  1 3   4
 
 Input : [7,6,5,2,1,3,4]
 Output : True
 
 */
 
 // Time : O(nlogn)

class Solution {
public:
    
    bool ans = true;   // boolean variable to store our final answer if tree is balanced or not
    
    int height(TreeNode* root){
        if(root == NULL)
            return 0;    // if root is empty return
        
        int left = height(root->left);   // traverse left subtree
        int right = height(root-> right);  // traverse right subtree
        
        if(abs(left - right) > 1) // if difference b/w left & right is > 1, return false
        ans = false;
        
        return max(left , right) + 1;   // return height of tree
    }
   
    bool isBalanced(TreeNode* root) {
       height(root);  // calling height function
       return ans;
    }
};