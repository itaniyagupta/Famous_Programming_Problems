// Problem Statement Link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class solution{
	public:
		bool comparison(Job a, Job b) 
		{ 
			 return (a.profit > b.profit); 
		}

		void printJobScheduling(vector<int> job, int n) 
		{ 
			// Sort all jobs according to decreasing order of prfit 
			sort(job, job+n, comparison); 
		  
			vector<int> result(n);  
			vector<bool> slot(n);  
		  
			// Initializing all slots to be free 
			for (int i=0; i<n; i++) 
			{
				slot[i] = false; 
			}
		  
			for (int i=0; i<n; i++) 
			{ 
				//  start from the last possible slot) 
			   for (int j=min(n, job[i].dead)-1; j>=0; j--) 
			   { 
				  if (slot[j]==false) 
				  { 
					 result[j] = i;  
					 slot[j] = true; 
					 break; 
				  } 
			   } 
			} 
		  
		  
			for (int i=0; i<n; i++) 
			   if (slot[i]) 
				 return job[result[i]].id; 
		}
};