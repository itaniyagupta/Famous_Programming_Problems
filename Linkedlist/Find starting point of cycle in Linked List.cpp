// Problem Statement Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *detectCycle(ListNode *head) {
		  unordered_set<ListNode*> s;
        ListNode* temp = head;
        while(head != NULL){
            if(s.find(temp) != s.end())
                return temp;
            s.insert(temp);
           temp = temp->next;
            
        }
        return NULL; 
    }
};
 
 //Floyd's cycle detection Algo
 // Time : O(n); Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     
        ListNode *fast = head;
        ListNode *slow = fast;
        
        while(slow != NULL && fast != NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
    
            if(slow == fast)
            {
                fast = fast;
                slow = head;

                while(slow != fast)
                {
                    slow = slow->next;
                    fast=fast->next;
                }
                 return slow;
            }  
        }
        return NULL;
    }
};

