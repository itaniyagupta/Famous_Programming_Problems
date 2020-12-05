// Problem statement Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 // Inorder Traversal & storing array
 // Time : O(n); Space : O(n)

class Solution {
  public:
     void getInorder(TreeNode* root, vector<int>& arr)
     {
           if(root==NULL)
            return;
           getInorder(root->left, arr);
           arr.push_back(root->val);
           getInorder(root->right, arr);
     }
    
    int kthSmallest(TreeNode* root, int k) {
           if(root == NULL)
            return -1; 
         
           vector<int> arr;
           getInorder(root, arr);
		   int count = 1;
           int index = arr.size()- 1;
           while(count < k)
           {
              index--;
              count++;
           } 
           return arr[index];
        }
};

// AUGMENTED BST
// Time : O(logn); Space : O(1)

/**
  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      int lCount;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr), lcount(0) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr)  lCount(0) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), lCount(0) {}
  };
 */

class Solution{
    public:
        int kthSmallest(TreeNode* root, int k) {
               if(root==NULL)
                  return -1;
               if(root!= NULL)
               {
                 TreeNode* temp=root;
                  while(temp != NULL)
                  {
                      int count =0;
                     if(temp->lcount+1==k)
                        return temp->val;
                     else if(k > temp->lcount+1 == k)
                     {
                         k=k-(temp->lcount+1);
                        temp= temp->left;
                     }
                    else
                    {
                     temp = temp->right;   
                    }
                }
              }
        return -1;
        }
    };
    