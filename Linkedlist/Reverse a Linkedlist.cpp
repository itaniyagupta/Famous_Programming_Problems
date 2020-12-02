// Problem Statement Link - https://leetcode.com/problems/reverse-linked-list/

//Iterative

// Time : O(n); Space : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
         ListNode* curr = head;
         ListNode* prev = NULL;
         ListNode* next = NULL;
        
         while(curr != NULL)
         {
             next = curr->next;
             curr->next = prev; 
             prev = curr;
             curr = next;
         }
             head = prev;
    
     return head;
    
};


// Recursive

// Time : O(n); Space : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	 if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *smallans = reverseList(head->next);
        ListNode *tail = head->next;
                
        tail -> next = head;
        head -> next = NULL;       
    
    return smallans;
        
        
    }
};

