// Problem Statement Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
   TreeNode* buildTree(const vector<int>& nums, int start, int end)
    {
       if ( end < start )
        {
            return NULL;
        }
        
        int root_pos = start + (end - start) / 2;

        int root_val = nums[root_pos];
       
       TreeNode *root = new TreeNode(root_val);
        
        root->left = buildTree(nums, start, root_pos - 1);
        root->right = buildTree(nums, root_pos + 1, end);
        
        return root;
   }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
          return buildTree(nums, 0,  nums.size() - 1);
       
    }
};