// Problem statement Link - https://leetcode.com/problems/middle-of-the-linked-list

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

 // Two Pointer
 // Time : O(n); Space : O(1)
 class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
      ListNode *slow = head;
      ListNode *fast = head;
        
      while(fast != NULL && fast->next != NULL)
      {
          slow = slow->next;
          fast = fast->next->next;
          
      }
        return slow;
        
    }
};

// Two Pass
// Time : O(n); Space : O(1)

class Solution {
public:
   ListNode* middleNode(ListNode* head) {
        int l=0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            l++;
        }
        temp = head;
        int count = 0;
           // Incrementing temp length/2 times
        while (count < l/2) {
            temp = temp->next;
            count++;
        }
        return temp;
   }
};