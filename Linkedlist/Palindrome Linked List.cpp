// Problem Statement Link - https://leetcode.com/problems/palindrome-linked-list/

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
 
// Using stack
// Time : O(n); space : O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
              if(head == NULL or head->next == NULL)
              {
                   return true;
              }
                
              stack <int> s;
              ListNode* temp = head;
             
              while(temp != NULL)
              {
                s.push(temp->val);
                 temp=temp->next;
              }
              temp = head;
             
              while(temp != NULL)
              {
                 int topOfStack = s.top();
                 s.pop();
                 if(topOfStack != temp->val)
                    return false;
                 temp=temp->next;
              }
              return true;
    }
};

// Time : O(n); space : O(1)

bool isPalindrome(ListNode* head) {
        if(head != NULL || head->next == NULL)
		{
			return true;
		}
        if(head->next->next == NULL)
		{
			return head->val == head->next->val;
		}
		
        ListNode *slow = head, *fast = head, *temp1=NULL,*temp2=NULL;
        while(fast->next != NULL && fast->next->next != NULL)
		{
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        while(fast != NULL){
            temp1 = fast->next;
            fast->next = temp2;
            temp2 = fast;
            fast = temp1;
        }
        slow->next = temp2;
        fast = slow->next; 
        slow = head;
        while(fast != NULL){
            if(fast->val != slow->val)return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

// Recursion
// Time : O(n); space : O(n)

class Solution{
  public:  
    bool isListPalindrome(ListNode* &leftmostNode, ListNode* rightmostNode)
        {
            if(rightmostNode == NULL)
              return true;
            bool resultSublist = isListPalindrome(leftmostNode, rightmostNode->next);
            if(resultSublist == false)
            {
              return false;
            }
            bool result = leftmostNode->val == rightmostNode->val;
            leftmostNode = leftmostNode->next;
            return result;
        }
    
      bool isPalindrome(ListNode* head) {
          return isListPalindrome(head, head);
      }
};