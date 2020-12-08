// Problem statement link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
    ListNode* helper(ListNode* head) 
    { 
		ListNode* res = head; 
		ListNode* temp, prev = NULL; 
	 
		int carry = 1, sum; 
	 
		while (head != NULL) 
		{ 
			sum = carry + head->data; 
	 
			carry = (sum >= 10)? 1 : 0; 
	 
			sum = sum % 10; 
	 
			head->data = sum; 
	 
			temp = head; 
			head = head->next; 
		} 
	  
		if (carry > 0) 
			temp->next = newNode(carry); 
			
		return res; 
    } 
 
	ListNode* addOne(ListNode* head) 
	{ 
		head = reverse(head); 
		head = helper(head); 
	return reverse(head); 
	} 
};