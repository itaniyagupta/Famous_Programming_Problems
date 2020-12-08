// Problem statement link - https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
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

// Time : O(n logn); Space: O(1)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
			return head;
		
		ListNode* lefthalf;
		ListNode* righthalf;
		
		findHalves(head, &lefthalf, &righthalf);
		lefthalf = sortList(lefthalf);
		righthalf = sortList(righthalf);
		head = merge(lefthalf, righthalf);
    
        return head;
    }
    ListNode* merge(ListNode* lefthalf, ListNode* righthalf)
	{
		ListNode* result;
		
		if(lefthalf == NULL)
			return righthalf;
		
		else if (righthalf == NULL)
			return lefthalf;
        
        else
        {
               if(lefthalf->val <= righthalf->val)
            {
                result = lefthalf;
                result->next = merge(lefthalf->next, righthalf);
            }
            else
            {
                result = righthalf;
                result->next = merge(lefthalf, righthalf->next);
            } 
        }	
		return result;
	}
	
	void findHalves(ListNode* head, ListNode** lefthalf, ListNode** righthalf) {
		ListNode* slow = head;
		ListNode* fast = head->next;
		
		while(fast != NULL)
		{
			fast = fast->next;
			if(fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*lefthalf = head;
		*righthalf = slow->next;
		slow->next = NULL;
	}
};