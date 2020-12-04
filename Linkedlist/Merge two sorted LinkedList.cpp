Problem Statement Link - https://leetcode.com/problems/merge-two-sorted-lists/

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
 
 // Iterative - In-Place Using two pointer
 // Time : O(n+m); Space : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
         if (l1 == NULL) return l2;
         if (l2 == NULL) return l1;
        
        ListNode* fhead= NULL;
        ListNode* ftail= NULL;
        
        if(l1->val <= l2->val)
        {
            fhead = l1;
            ftail = l1;
            l1 = l1->next;
        }
        else
        {
            fhead = l2;
            ftail = l2;
            l2 = l2->next;
        }
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
				ftail -> next = l1;
				ftail = ftail -> next;
				l1 = l1->next;
            }
            else
            {
				ftail -> next = l2;
				ftail = ftail -> next;
				l2= l2->next;
            }   
        }
        
      if(l1 == NULL)
        {
            ftail-> next = l2;
        }
        if(l2 == NULL)
        {
            ftail-> next = l1;
        }    
    return fhead;    
    }
};

// Recursive
// Time : O(n+m); Space : O(n+m)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		ListNode* output = NULL;
		if (l1->val < l2->val)
		{
			output = l1;
			l1->next = mergeTwoLists(l1->next,l2);
		}
		else
		{
			output = l2;
			l2->next = mergeTwoLists(l1,l2->next);
		}
		return output;
	}
};