Problem Statement Link here - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
 
 // Two Pass Approach
 // Time : O(n); Space : O(1)
 
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* temp = head;
            int end_index = 0;
            while(temp != NULL) {
                end_index++;
               temp = temp->next;
            }
            int index_to_remove = end_index - n;
            int i = 0;
            temp = head;
            ListNode* prev = NULL;
            while(i < index_to_remove) {
                prev = temp;
               temp = temp->next;
                i++;
            }
            if(temp== head) 
            {
                head = head->next;
            }
            else if(prev != NULL) 
            {
                prev->next = temp->next;
            }
            delete temp;
            return head;
    }
};