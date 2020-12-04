// Problem Statement - https://leetcode.com/problems/odd-even-linked-list/

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

// Two Pointer Approach
//Time : O(n); Space : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
         if(head == NULL or head->next == NULL) 
         {
             return head;
         }
        
        ListNode* oddPt = head;
        ListNode* evenPt = head->next;
        ListNode* even = head->next;
        
        while(evenPt != NULL && evenPt->next != NULL)
        {
            oddPt -> next = oddPt->next->next;
            oddPt = oddPt->next;
            evenPt->next = evenPt->next->next;
            evenPt = evenPt->next;
        }
        oddPt->next = even;
        return head;
    }
};