/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Using same approach as LCA of binary tree
// Time: O(n); Space: O(n) 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        
        if(root == NULL) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left != NULL && right != NULL)
            return root;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        if(left != NULL) return left;
        if(right != NULL) return right;
        
        return NULL;
    }
};

// recursive
// Time:  O(logn); Space : O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           
           if (p->val > root->val && q->val > root->val) 
           {
                return lowestCommonAncestor(root->right, p, q);
            } 
            else if (p->val < root->val && q->val < root->val) {
                return lowestCommonAncestor(root->left, p, q);
            } 
           else 
            {
                return root;
            }
    }
};

// Iterative
// Time: O(logn); Space : O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		
        if(root == NULL) return root;
        
        while (root != NULL) 
		{
			if (p->val > root->val && q->val > root->val) 
            {                
				root = root->right;
			} 
			else if (p->val < root->val && q->val < root->val) 
            {
				root = root->left;
			} 
			else
			{
				return root;
			}
		}
		return root;
	}
};
