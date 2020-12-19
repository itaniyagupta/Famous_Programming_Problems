// Problem Statement link -

// Brute Force
// Time : O(n^2); space : O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int  n = gas.size();
		for (int i = 0; i < n; i++) {
		  int   fuel = gas[i];
			bool isAmple = true;  // determine a valid starting point
			for (int j = 0 ; j < n; j++) {
				int currStation = (i + j) % n;
				int nextStation = (currStation + 1) % n;
				fuel = fuel - cost[currStation];
				// not reachable from currStation to nextStation
				if (fuel < 0) { 
					isAmple = false;
					break;
				}
				// refuel in nextStation
				fuel = fuel + gas[nextStation];
			}
			if (isAmple) {
				return i;
			}
		}
	return -1;
    }
};


// Greedy
// Time : O(n); space : O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     
        int start = 0;
        int total = 0;
        int tank = 0;
        for( int i = 0;i < gas.size(); i++) {
            tank = tank + gas[i] - cost[i];
            if(tank < 0) 
            {
                start = i+1;
                total= total + tank;
                tank=0;
            }
        }
        if(total + tank < 0) 
        {
            return -1;
        }
        else 
        { 
            return start;
        }
    }
};