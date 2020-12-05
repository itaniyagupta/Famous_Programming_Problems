// Problem Statement Link - https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

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
 
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL) return NULL;
		 
		TreeNode* min = root; 
		 while (min->left != NULL)  
			{  
				min = min->left;  
			}  
			return(min->val);		
	}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL) return NULL;

		TreeNode* max = root; 
		 while (max ->right != NULL)  
			{  
				max = max->right;  
			}  
			return(max->val);
	}
};