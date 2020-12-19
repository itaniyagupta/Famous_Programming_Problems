// Problem Statement Link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *right;
 *     ListNode *down;
 *     ListNode(int x) : val(x), right(NULL) {}
 * };
 */

class solution{
	public:
		ListNode* merge( ListNode* a, ListNode* b){ 
			if (a == NULL) 
				return b; 
		  
			if (b == NULL) 
				return a; 
		  
			ListNode* result; 
			if (a->val < b->val) 
			{ 
				result = a; 
				result->down = merge(a->down, b); 
			} 
			else
			{ 
				result = b; 
				result->down = merge(a, b->down); 
			} 
			result->right = NULL; 
			return result; 
		} 
		  
		ListNode* flatten (ListNode* root){ 
			if (root == NULL || root->right == NULL) 
				return root; 
		 
			return merge( root, flatten(root->right)); 
		}
};