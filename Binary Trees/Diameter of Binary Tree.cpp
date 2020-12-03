// problem statement link - https://leetcode.com/problems/diameter-of-binary-tree/

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
    int ans =0;
    int diameter(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = diameter(root->left);
        int right = diameter(root->right);
        ans = max(ans, left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
    
        if(root==NULL){
            return 0;
        }
        diameter(root);
        return ans;
        
    }    
};

// Iterative
// Time : O(n)
 
class Solution {
  public:
	 int diameterOfBinaryTree(TreeNode* root) {
		 if(root==NULL)
		 {
            return 0;
         }
        int diameter = 0;
        unordered_map<TreeNode*, int> map;
        stack<TreeNode*> p;
        p.push(root);
        while (!p.empty()) 
        {
            TreeNode* node = p.top();
            if (node -> left != NULL && map.find(node -> left) == map.end())
            {
                p.push(node -> left);
            } else if (node -> right != NULL && map.find(node -> right) == map.end())
            {
                p.push(node -> right);
            } else 
            {
                p.pop();
                int leftmax = map[node -> left], rightmax = map[node -> right];
                map[node] = max(leftmax, rightmax) + 1;
                diameter = max(diameter, leftmax + rightmax);
            }
        }
        return diameter;
	 }
};
	