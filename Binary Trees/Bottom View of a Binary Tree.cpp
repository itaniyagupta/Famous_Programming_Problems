// Problem Statement Link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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
 
 /*
 
     7   <- level 0
	/ \
   6   5  <- level 1
  /	\  / \
 2  1 3   4 <- level 2
 
 Input : [7,6,5,2,1,3,4]
 Output : 2 1 3 4
 
 */

// Time: O(nlogn); Space: O(n)


//  In code, dist -> horizontal distance & level is vertical level of node
class Solution {
public:
      // Recursive function to do pre-order traversal of the tree & fill the map
		 void Bottomside(TreeNode* root, int dist, int level, map<int,pair<int,int>> &map)
    {
            if (root == nullptr)  // if root is empty return
                return; 
          // if current level is greater than max level so far for same horizontal distance or horizontal distance is seen for ist time, then update map
            if (map.find(dist) == map.end() || level >= map[dist].second)
            {
               
                map[dist] = { root->val, level }; // update value and level for current distance
            }

            Bottomside(root->left, dist - 1, level + 1, map); // Traverse left subtree by decrementing distance & incrementing level
            Bottomside(root->right, dist + 1, level + 1, map); // Traverse left subtree by incrementing distance & incrementing level
        }

      
        vector<int> BottomView(TreeNode* root)
        {
            map<int, pair<int, int>> map;  // map to store Horizontal distance, node value & corresponding level
			                              // key -> relative horizontal distance of the node from root node and
                                         // value -> pair containing node's value and its level
           
		   Bottomside(root, 0, 0, map);  // calling function with parameters root, level as 0, distance as 0 & map
            
            vector<int> ans;  // vector to store our final result
             for (auto it: map){
                ans.push_back(it.second.first);   // traverse map & store value in ans
             }
        return ans;
        }
};

     