// problem Statement Link - https://leetcode.com/problems/merge-two-binary-trees/

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
 Input:
 Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
*/
 
 
 // Recursive
 
class Solution {
	public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
       
          if(t1==NULL) // if root of tree 1 is null, return tree 2
            return t2;
          if(t2==NULL)
            return t1; // if root of tree 2 is null, return tree 1
        
          t1->val=t1->val+t2->val; // tree 1 root value = sum of tree 1 + tree 2
        
          t1->left=mergeTrees(t1->left,t2->left); // left subtree
        
          t1->right=mergeTrees(t1->right,t2->right); // right subtree
        
         return t1;
    }
};



