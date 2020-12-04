// Problem Statement Link- https://leetcode.com/problems/remove-linked-list-elements/ 

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
 
 // Time : O(n); Space : O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp= head;
        ListNode* prev= head;
        
        while (temp!= NULL)
        {
           if(temp->val == val)
           {
                if(temp == head) //if val is in ist node itself
                {
                    head = temp->next;
                }
               else
               {
                 prev->next = temp->next;
                 temp=temp->next;
               }
           }
           else
            {
                prev = temp;
                temp =temp->next; 
           }
        }
        return head;
    }
};