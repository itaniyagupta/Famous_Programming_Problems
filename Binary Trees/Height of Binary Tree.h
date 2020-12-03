//Problem Statement Link - 

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
// Time : O(n); Space: O(n)
	
class Solution {
 public:
	int height(TreeNode* root) {
    if(root == NULL)
	{
		return 0;
	}
	    int left = height(root->left);
        int right = height(root->right);
        int height = max(height(root.left), height(root.right));
        return height + 1;
    }
};

// Iterative
// Time : O(n); Space: O(n)

class Solution {
 public:
	int height(TreeNode* root) { 
		if (root == NULL) 
		{
			return 0;
		}
		queue<int> q;
		q.push(root);
		int height = 0;
		
		while(!q.empty()) { 
			int size = q.size();
			if (size == 0) 
			{
				return height;
			}
			height = height + 1;
			
			while (size > 0) 
			{ 
				TreeNode* node = q.front();
				q.pop();
				
				if (node->left != NULL) 
				{
					q.push(node->left)
				}
				
				if (node->right != NULL) 
				{
					q.push(node->right)
				}
				size--;
			}
		}
		return height;
	}
};