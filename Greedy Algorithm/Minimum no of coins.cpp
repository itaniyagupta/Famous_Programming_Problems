
// Time : O(V); Space : O(1)
class solution{
	public:
	   void findMin(vector<int> denomination, int V)
	   {
		    int n = denomination.size();
			sort(denomination, denomination + n);
		 
			vector<int> ans;
		 
			for (int i = n - 1; i >= 0; i--) {
		
				while (V >= denomination[i])
				{
					V -= denomination[i];
					ans.push_back(denomination[i]);
				}
			}		
		return ans;
	   }
};