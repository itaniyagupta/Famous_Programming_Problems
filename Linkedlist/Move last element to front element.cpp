// Problem statement link - https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

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

class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            
            if(head == NULL)
            {
                return head;
            }
            ListNode* temp = head;
            ListNode* prev = head;
            
            while(temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
           
            prev -> next = NULL;
            temp -> next = head;
            head = temp;
            
        return head;
        }
};