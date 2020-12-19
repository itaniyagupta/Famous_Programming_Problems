// Problem Statement Link - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* prev= head;
         int count =0;
         
        for(int i=0;i<k;i++)
        {
            if(!prev) return head;
            prev=prev->next;
        }
        ListNode* last=head;
        for(int i=0;i<k;i++)
        {
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        last->next= reverseKGroup(last->next,k);
        return prev;  
    }
};
