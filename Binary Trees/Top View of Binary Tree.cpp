
// Time: O(nlogn)l; Space: O(n)

class Solution {
public:
		 void Topside(TreeNode* root, int dist, int level, map<int,pair<int,int>> &map)
    {
            if (root == nullptr)
                return;
        
            if (map.find(dist) == map.end() || level < map[dist].second)
            {
               
                map[dist] = { root->val, level };
            }

            Topside(root->left, dist - 1, level + 1, map);
            Topside(root->right, dist + 1, level + 1, map);
        }

      
        vector<int> TopSideView(TreeNode* root)
        {
            map<int, pair<int, int>> map;
            Topside(root, 0, 0, map);
            
            vector<int> ans;
             for (auto it: map){
                ans.push_back(it.second.first); 
             }
        return ans;
        }
};

     