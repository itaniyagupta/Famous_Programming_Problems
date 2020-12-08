// Problem statement link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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
 
 // when extra space not allowed
 // Two Pointer approach
 // Time : O(n^2); Space : O(1)
 
class Solution {
 public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* curr = head;
        
		while(curr != NULL)
		{
			ListNode* temp = curr;
			while(temp->next != NULL)
			{
				if(temp->next->val = curr->val)
				{
					temp->next = temp->next->next;
					delete temp->next;
				}
				else
				{
					temp = temp->next;
				}
			}
			curr = curr->next;
		}
	return head;
	}
};

// Using hash map
// Time: O(n); Space : O(1)

class Solution {
 public:
    ListNode* deleteDuplicates(ListNode* head) {
		unordered_set<int> set;
        ListNode* prev = null;
        while (head != null) 
		{
 			if (set.find(head->val) != set.end()) 
            {
                prev->next = head->next;
            } 
			else 
			{
                set.add(head->val);
                prev = head;
            }
           head = head->next;
        }
    }
};	

