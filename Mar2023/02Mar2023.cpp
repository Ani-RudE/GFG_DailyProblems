//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if(n==0) return 0;
        if(n > 1 && k == 1) return -1;
        vector<vector<int>> dp(n, vector<int>(k));
        
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 0; i < k; i++)
        {
            dp[0][i] = costs[0][i];
            if(costs[0][i] < min1)
            {
                min2 = min1;
                min1 = costs[0][i];
            }
            else if(costs[0][i] < min2)
            {
                min2 = costs[0][i];
            }
            
        }
        
        int currmin1 = INT_MAX, currmin2 = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(dp[i-1][j] == min1)
                {
                    dp[i][j] = costs[i][j]+min2;
                }
                else
                {
                    dp[i][j] = costs[i][j]+min1;
                }
                
                if(dp[i][j] < currmin1)
                {
                    currmin2 = currmin1;
                    currmin1 = dp[i][j];
                }
                else if(dp[i][j] < currmin2)
                {
                    currmin2 = dp[i][j];
                }
            }
            min1 = currmin1;
            min2 = currmin2;
            currmin1 = INT_MAX;
            currmin2 = INT_MAX;
        }
        
        
        return min1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends