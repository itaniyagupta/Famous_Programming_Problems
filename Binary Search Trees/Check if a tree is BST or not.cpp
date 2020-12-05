// Problem Statement Link - https://practice.geeksforgeeks.org/problems/check-for-bst/1

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

 // Brute Force
 // Time : O(n^2); Space : O(n)
 
class Solution {
public:
 
	int getMin(TreeNode* root)
	{
		TreeNode*  temp = root
		while(temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp->val;
	}

	int getMax(TreeNode* root)
	{
		TreeNode*  temp = root
		while(temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->val;
	}

	bool isBST(TreeNode* root)
	{
		if (root == NULL)
		{
			return true;
		}
		
		int max_left = getMax(root->left);
		int min_right = getMin(root->right);
		
		if (max_left > root->val || min_right < root->val)
		{
			return false;
		}
		
		if (isBST(root->left) && isBST(root->right))
		{
			return true;
		}
		return false;    
	}
};

// Another Brute force
// Time : O(n); space : O(h)

class Solution {
public:
	bool helper(TreeNode*  root, int range_min, int range_max)
	{
		if(root == NULL)
		{
			return true;
		}
		
		if (root->val < range_min || root->val > range_max)
		{
			return false;
		}
		
		if (helper(root->left, range_min, root->val-1))
		{
			if (helper(root->right, root->val+1, range_max))
			{
				return true;
			}
		}
		return false;
	}

	bool isBST(TreeNode*  root)
	{
		if (helper(root, INT_MIN, INT_MAX))
		{
			return true;
		}
		return false;
	}
};

// Inorder Traversal
// Time : O(n); Space: O(n)
class Solution {
public:
	void Inorder(TreeNode* root, vector<int>& arr)
	{
		if (root == NULL)
			return;
		Inorder(root->left, arr);
		arr.push_back(root->val);
		Inorder(root->right, arr);
	}
	boolean isBST(BSTNode root)
	{
		vector<int> arr; 
		Inorder(root, arr) 
		for(i = 1; i < arr.size() - 1; i++)
		{
			if (arr[i] < arr[i-1])
				return false;
		}
		return true;
	}
};