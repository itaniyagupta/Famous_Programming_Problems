// Problem Statement Link - https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Hashing
// Time: O(n); space: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> s;
        while(head != NULL){
            if(s.find(head) != s.end())
                return true;
            s.insert(head);
            head = head->next;
            
        }
        return false; 
    }
};

// Floyd's cycle detction algortihm
// Time : O(n); Space : O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *slow=head,*fast=head;
        
        while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
            
            slow = slow->next;              
            fast = fast->next->next;        
            
            if(slow==fast)
                return true;
        }
        
        return false;
        
    }
};