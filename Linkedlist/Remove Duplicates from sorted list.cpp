// Problem Statement Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
 
// Iterative
// Time : O(n); Space : O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* current = head;
        
     while(current!=NULL && current->next!=NULL)
     {
         ListNode* NextNode = NULL;
         if(current->val == current->next->val)
         {
             NextNode = current->next->next;
             delete current->next;  
             current->next = NextNode;
         }
         else
             current = current->next;
     }
       return head; 
    }
};

// Recursive
// Time : O(n); Space : O(n)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL or head->next==NULL)
            return 0;
		if(head->val== head->next-> val)
		{
			ListNode* NextNode = head->next->next;
			delete head->next;
			head->next = NextNode;
			deleteDuplicates(head);
	   }
		else
        {
            deleteDuplicates(head->next);
        }
        return head;
	}
};