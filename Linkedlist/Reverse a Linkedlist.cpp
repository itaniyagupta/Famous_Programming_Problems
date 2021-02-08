// Problem Statement Link - https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


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
             next = curr->next; // store next node Before changing next of current
             curr->next = prev; // here reversing happens; curr->next points to prev
             prev = curr;     // Move prev and curr one step forward 
             curr = next;
         }
             head = prev; // head node is at prev
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
	                           //	Divide the list in two parts - head node &  rest of the linked list
        ListNode *smallans = reverseList(head->next); // calling reverse for the rest of the linked list.
        ListNode *tail = head->next;
                                            //  Link rest to first & then fix head pointer
        tail -> next = head;       
        head -> next = NULL;       
    
    return smallans;
        
        
    }
};

