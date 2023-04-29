//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int powerfullInteger(int n, vector<vector<int>> &intervals, int k)
     {
          map<int, int> m;
          for (int i = 0; i < intervals.size(); i++)
          {
               m[intervals[i][0]] += 1;
               m[intervals[i][1] + 1] -= 1;
          }

          int ans = -1;
          int sum = 0;
          int c = 0;
          
          for (auto it : m)
          {
               sum += it.second;
               if (sum >= k)
               {
                    c = 1;
               }
               
               if (sum < k && c == 1)
               {
                    ans = it.first - 1;
                    c = 0;
               }
          }

          return ans;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int n, k;
          cin >> n;
          vector<vector<int>> intervals(n, vector<int>(2));
          for (int i = 0; i < n; i++)
          {
               cin >> intervals[i][0] >> intervals[i][1];
          }
          cin >> k;
          Solution ob;
          cout << ob.powerfullInteger(n, intervals, k) << endl;
     }
     return 0;
}
// } Driver Code Ends