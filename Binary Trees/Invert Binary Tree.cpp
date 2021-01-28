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
 
 /*
 
 Input:
     7   
	/ \
   6   5  
  /	\  / \
 2  1 3   4
 
 Output: 
     7   
	/ \
   5   6  
  /	\  / \
 4  3 1   2
*/
 
 
// Using Recursion
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
         if(root==NULL)
            return NULL;   // If root is empty, return
        
		// Swapping left & right nodes
        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        invertTree(root->left);    // Recursive calling left subtree
        invertTree(root->right);  // Recursive calling Right subtree
   
        return root;
        
    }
};

// Using Level order Traversal

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) 
            return NULL;     // If root is empty, return
        
        queue<TreeNode*> q;   // queue to store values of tree nodes
        q.push(root);  // push root to queue
        while(!q.empty()) {       // traverse till queue is empty
            TreeNode * temp = q.front();   // variable of type TreeNode* to store top value of the queue
            q.pop();		// deleting top value of queue
            swap(temp->left, temp->right); // swapping values on left of temp and right of temp
            if(temp->left) { // if left side of temp exists, push it into queue
                q.push(temp->left);
            }
            if(temp->right) { // if right side of temp exists, push it into queue
                q.push(temp->right);
            }
        }
        return root;
    }
};