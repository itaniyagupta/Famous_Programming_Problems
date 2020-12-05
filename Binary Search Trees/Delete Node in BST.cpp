// Problem Statement Link - https://leetcode.com/problems/delete-node-in-a-bst/

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

 // Recursive Using property of BST : left<root<right
 
class Solution {
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL) return NULL;
        if (root->val > key) 
        {
            root->left = deleteNode(root->left, key);
        } 
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        } 
        else 
        {
            if (root->left == NULL) 
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
             }
          if (root->right == NULL) 
           {
                TreeNode* temp = root->left;
                delete root;
                return temp;
           } 
           if(root->right != NULL && root-> left != NULL)
           {
                TreeNode* Min = root->left;
                while (Min->right != NULL)
                {
                   Min = Min->right;
                }
                root->val = Min->val;
                root->left = deleteNode(root->left, Min->val);
           }
        }
        return root;
    }
};

// Recursive - Traversing all nodes
class Solution {
 public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) 
		{
			return NULL;
		}
        if (root->val == key) 
		{
            if (root->right == NULL) 
			{
				return root->left;
			}
            else 
			{
                TreeNode* Min = root->right;
                while (Min->left != NULL) 
				{
					Min = Min->left;
                    swap(root->val, Min->val);
				}
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};