// Problem statement Link - https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time : O(m+n);
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         if (l1 == NULL and l2 == NULL) return NULL;
			else if (l1 == NULL) return l2; 
			else if (l2 == NULL) return l1; 
      

			int a = l1->val + l2->val;
			ListNode *l3 = new ListNode(a % 10);
			
            l3->next = addTwoNumbers(l1->next,l2->next);
                if (a >= 10) 
                {
                     l3->next = addTwoNumbers(l3->next, new ListNode(1));
                }  
			return l3;
    }
};

