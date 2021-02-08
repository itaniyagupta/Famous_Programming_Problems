// Problem statement Link - https://leetcode.com/problems/middle-of-the-linked-list

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

 /* Input : [1,2,3,4,5]
    output : [3,4,5]
	
	 Input : [1,2,3,4,5,6]
    output : [4,5,6]
	
	if two middles, return 2nd middle node
	
	*/
 
 // Two Pointer
 // Time : O(n); Space : O(1)
 class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
      ListNode *slow = head; // Pointer slow is initialised with head of the linkedlist
      ListNode *fast = head; // Pointer head is initialised with head of the linkedlist
        
      while(fast != NULL && fast->next != NULL) // Loop till fast is Null or node next to fast is NULL
      {
          slow = slow->next;          // slow is incremented by one node
          fast = fast->next->next;  // fast is incremented by two node, so slow will be in middle when fast reaches end of linkedlist
          
      }
        return slow;  // return the node where slow points 
    }
};


/* Visualization

Given : 1 -> 2 -> 3 -> 4 -> 5

  1 -> 2 -> 3 -> 4 -> 5         1 -> 2 -> 3 -> 4 -> 5			 1 -> 2 -> 3 -> 4 -> 5             3 -> 4 -> 5
  |                        =>        |    |              =>                |         |    =>    3 is the middle node 
 slow								slow  fast							  slow      fast		of the Linkedlist
 fast

 Given : 1 -> 2 -> 3 -> 4 -> 5-> 6

  1 -> 2 -> 3 -> 4 -> 5 -> 6        1 -> 2 -> 3 -> 4 -> 5			 1 -> 2 -> 3 -> 4 -> 5 -> 6         1 -> 2 -> 3 -> 4 -> 5 -> 6               4 -> 5-> 6
  |                            =>        |    |              =>                |         |       =>                    |         |     =>   4 is the second middle node 
 slow								   slow  fast							  slow      fast		                  slow      fast              of the Linkedlist
																     (Here fast-> next is not NULL)
*/
*/



// Two Pass
// Time : O(n); Space : O(1)

class Solution {
public:
   ListNode* middleNode(ListNode* head) {
        int l=0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            l++;
        }
        temp = head;
        int count = 0;
           // Incrementing temp length/2 times
        while (count < l/2) {
            temp = temp->next;
            count++;
        }
        return temp;
   }
};