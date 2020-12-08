// Problem statemnt link - https://leetcode.com/problems/insertion-sort-list/

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

// Time : O(n^2); Space :O(1)

class Solution {
public:
    ListNode* helper(ListNode* temp, ListNode* curr)
	{
		if(temp == NULL || temp->val >= curr->val)
		{
			curr->next = temp;
			return curr;
		}
		else
		{
			ListNode* temp3 = temp;
			while(temp3->next != NULL && temp3->next->val < curr->val)
				temp3 =  temp3->next;
			    curr->next = temp3->next;
			   temp3->next = curr;
		}
		return temp;
	}
    
    ListNode* insertionSortList(ListNode* head) {
            ListNode* curr = head;
		ListNode* temp = NULL;
		while (curr != NULL)
		{
			ListNode* temp2 = curr->next;
			temp = helper(temp,curr);
			curr = temp2;
		}
		return temp;        
    }
};