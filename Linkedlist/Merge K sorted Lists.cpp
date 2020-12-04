// Problem Statement Link - https://afteracademy.com/blog/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> temp;
        if(lists.size() == 0)
        {
            return NULL;
        }
         for (int i=0; i < lists.size();i++)
         {
            ListNode* head = lists[i];
            while(head != NULL)
            {    
                temp.push_back(head->val);
                head=head->next;
            }
         }
        if(temp.size()==0) 
        {
             return NULL;    
        }
            
        sort(temp.begin(),temp.end());

        ListNode* ans = new ListNode(temp[0]);
        ListNode* cur = ans;
       
        for(int i=1;i<temp.size();i++)
        {
            cur->next = new ListNode(temp[i]);
            cur=cur->next;
        }
        return ans;
        
    }
};