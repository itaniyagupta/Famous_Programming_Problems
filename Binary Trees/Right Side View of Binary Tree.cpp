// Problem statemnt Link - https://leetcode.com/problems/binary-tree-right-side-view/submissions/; https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

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
     7   <- level 0
	/ \
   6   5  <- level 1
  /	\  / \
 2  1 3   4 <- level 2
 
 Input : [7,6,5,2,1,3,4]
 Output : 7 5 4
 
 */

 // Time: O(nlogn); Space: O(n)
 
class Solution {
public:
    
    vector<int> res;  // vector to store final result
    void rightView(TreeNode* root, int level, int *max_level){ 
            if (root==NULL)  // if root is empty return
            {
                return; 
            }
		// If curr level is more than max level so far, the push node into res
           // If this is the last Node of its level 
            if (*max_level < level) 
            { 
                res.push_back(root->val); // push node value into vector
                *max_level = level; 
            } 
 
            rightView(root->right, level+1, max_level); // visit right subtree before left subtree
            rightView(root->left, level+1, max_level); 
       }
    
    vector<int> rightSideView(TreeNode* root) {
     
        int max_level = 0;  // max level as 0
        rightView(root, 1, &max_level); 
        return res;
    }
};


