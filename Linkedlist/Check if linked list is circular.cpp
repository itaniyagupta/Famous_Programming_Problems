// Problem statement link - https://practice.geeksforgeeks.org/problems/circular-linked-list/1

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

 // Time : O(n); Space : O(1)

class solution{
 public:
	bool isCircular(ListNode* head) 
   { 
		if (head == NULL) 
		   return true; 
		ListNode* temp = head->next; 
		while (temp != NULL && temp != head) 
		{
		   temp = temp->next; 
		}
	    if(temp == head)
		{
			return true;
		}
	 return false;	
   }  
};