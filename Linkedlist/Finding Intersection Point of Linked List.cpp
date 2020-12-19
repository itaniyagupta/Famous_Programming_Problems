// Problem Statement Link - https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Finding size of list

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int size1=0,size2=0;
	ListNode *curr1=headA,*curr2=headB;
	while(curr1!=NULL)
	{
		size1++;
		curr1=curr1->next;
	}
	while(curr2!=NULL)
	{
		size2++;
		curr2=curr2->next;
	}
	curr1=headA,curr2=headB;
	if(size1>size2)
	{
		for(int i=0;i<size1-size2;i++)
		{
			curr1=curr1->next;
		}
	}
	else
	{
		for(int i=0;i<size2-size1;i++)
			curr2=curr2->next;
	}
	while(curr1!=NULL)
	{
		if(curr1==curr2)
			break;
		curr1=curr1->next;
		curr2=curr2->next;
	}
	return curr1;
    } 
};

// using Hash Map

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> nodeMap;
        ListNode *temp = headA;
        while(temp != NULL){
            if(nodeMap.find(temp) == nodeMap.end()){
                nodeMap[temp] = 1;
            }
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL){
            if(nodeMap.find(temp) == nodeMap.end()){
                nodeMap[temp] = 1;
            }
            else{
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};
