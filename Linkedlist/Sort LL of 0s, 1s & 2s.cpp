// Problem statement link - https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class solution{
	void sortList(ListNode* head)  
	{  
		vector<int> count[3] = {0, 0, 0};
		ListNode* ptr = head;  
	  
		while (ptr != NULL)  
		{  
			count[ptr->data] += 1;  
			ptr = ptr->next;  
		}  
	  
		int i = 0;  
		ptr = head;  
	  
		while (ptr != NULL)  
		{  
			if (count[i] == 0)  
				++i;  
			else
			{  
				ptr->data = i;  
				--count[i];  
				ptr = ptr->next;  
			}  
		}  
	}  
};