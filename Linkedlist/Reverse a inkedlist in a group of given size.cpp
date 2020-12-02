// Problem statement Link - https://leetcode.com/problems/reverse-linked-list-ii/

// Time : O(m+n)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    
        if (head == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next= NULL;
        
        for(int i=1; i<m; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        
        for(int i=m; i<n; i++) {
            if(curr->next == NULL) {
                break;
            }
            
            next = curr->next;
            curr->next = next->next;
            
            if (prev != NULL) {
                next->next = prev->next;
                prev->next = next;
            }
            else {
                next->next = head;
                head=next;
            }
        }
        return head;
    }
};
