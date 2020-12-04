// Problem Statement - https://leetcode.com/problems/invert-binary-tree/; https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/

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
 
// Using Recursion
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
         if(root==NULL)
            return root;
        
        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        invertTree(root->left);
        invertTree(root->right); 
   
        return root;
        
    }
};

// Using Level order Traversal



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        return root;
    }
};