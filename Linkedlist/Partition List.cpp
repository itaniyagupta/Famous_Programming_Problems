// Problem statement link  - https://leetcode.com/problems/partition-list/

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* beforeXstart = NULL;
        ListNode* beforeXend = NULL;
        ListNode* afterXstart = NULL;
        ListNode* afterXend = NULL;
       
        while(head != NULL)
        {
            ListNode* next= head->next; 
            head->next = NULL; 
            if(head -> val < x)
            {
                if (beforeXstart == NULL)
                {
                    beforeXstart = head;
                    beforeXend = beforeXstart;
                } 
                else 
                {
                    beforeXend->next = head;
                    beforeXend = head;
                }
            }
            else
            {
                 if (afterXstart == NULL)
                {
                    afterXstart = head;
                   afterXend = afterXstart;
                } 
                else 
                {
                    afterXend->next = head;
                   afterXend = head;
                }
            }
            head = next;
        }
        
        if (beforeXstart == NULL) {
            return afterXstart;
        } 
        
        beforeXend->next = afterXstart; 
        return beforeXstart;
    }
};