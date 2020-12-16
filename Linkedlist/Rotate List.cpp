// Problem Statement link - https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || k==0 || !head->next)
            return head;
        
        int count = 1;
        ListNode* temp=head;
        
        while(temp->next != NULL){
            count++;
            temp=temp->next;
        }
        
        k=k%count;
        k= count-k;
        
        temp->next=head;
        
        while(k--){
            temp = temp->next;
        }
        
        head=temp->next;
        
        temp->next=NULL;
        
        return head;
        
    }
};