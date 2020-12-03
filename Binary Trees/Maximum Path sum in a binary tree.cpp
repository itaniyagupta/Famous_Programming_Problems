//Problem Statement Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
 // Time : O(n)
class Solution {
public:
    
    int sum = INT_MIN;
    
	int maxpath(TreeNode *root){
           if(root == NULL)
           {
            return NULL;
           }
        
           int left =  maxpath(root->left);
           int right = maxpath(root->right);
        
        int max_single = max(max(left,right)+ root->val, root->val);
        int max_top = max(max_single, left+ right + root->val );
        
        sum = max(sum,max_top);
        return max_single;
    }
    
    int maxPathSum(TreeNode* root) {
        maxpath(root) ; 
        return sum;
    }
  
};

// Iterative
// Time : O(n)
 
class Solution {
  public:
	 int maxPathSum(TreeNode* root) {
		 if(root==NULL)
		 {
            return 0;
         }
		 
        unordered_map<TreeNode*, int> map;
        stack<TreeNode*> p;
       
		int sum = root->val;
		
        while(!p.empty() || root!=NULL)
		{
            while(root != NULL)
			{
                p.push(root);
                root = root->left;
            }
            
			TreeNode* node = p.top();
			
            if(node->right!=NULL && map.find(node->right)==map.end())
			{
                root = node->right;
            }
			else
			{
                p.pop();
                int l = map[node->left];
                int r = map[node->right];
				
                sum = max(sum, l+r+node->val);
                map[node] = node->val + max(l, r);
            }
        }
        return sum;
	 }
};
     