//Problem statement link - https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
       while(temp != NULL)
       {
            if(temp->next == NULL && prev!= head && prev != NULL )
            {
               temp->next = head->next;
               head->next = temp;
               head = temp->next;
               temp = temp->next;
               prev->next = NULL;
             }
         prev = temp;
         temp = temp->next;
       }
   }
};