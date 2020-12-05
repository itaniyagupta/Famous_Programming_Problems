//Problem statement link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // recursive
 // Time: O(n); Space : O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        if(root == nullptr) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
															// both the left & right subtree return some node, this means we have found LCA
        if(left != nullptr && right != nullptr) 
            return root; 
        
        if(root->val == p->val || root->val == q->val)
            return root;
                                                               //If the left or right subtree returns a non-NULL node, this means one of the two nodes was found below
        if(left != nullptr) return left;
        if(right != nullptr) return right;
        
        return nullptr;
    
    }
};
