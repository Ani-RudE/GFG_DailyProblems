//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int maxCoins(int n, vector<vector<int>> &ranges)
     {
          sort(ranges.begin(), ranges.end());
          map<int, int> partmax;
          int a = -1, b, c, d, e;
          for (b = n - 1; b >= 0; b--)
          {
               if (ranges[b][2] > a)
               {
                    a = ranges[b][2];
                    partmax[b] = a;
               }
          }
          partmax[INT_MAX] = 0;
          vector<int> edit;
          c = -1;
          for (b = 0; b < n; b++)
          {
               edit = {ranges[b][1], 0, 0};
               if (partmax.lower_bound(distance(ranges.begin(), lower_bound(ranges.begin(), ranges.end(), edit)))->first == b)
               {
                    e = -1;
                    for (d = b + 1; d < ranges.size(); d++)
                    {
                         if (ranges[d][2] > e)
                         {
                              e = ranges[d][2];
                         }
                    }
                    a = (e >= 0 ? e : 0) + ranges[b][2];
               }
               else
               {
                    a = partmax.lower_bound(distance(ranges.begin(), lower_bound(ranges.begin(), ranges.end(), edit)))->second + ranges[b][2];
               }
               if (a > c)
               {
                    c = a;
               }
          }

          return c;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;
          vector<vector<int>> a(n, vector<int>(3));
          for (int i = 0; i < n; i++)
          {
               cin >> a[i][0] >> a[i][1] >> a[i][2];
          }
          Solution ob;
          cout << ob.maxCoins(n, a) << endl;
     }
     return 0;
}
// } Driver Code Ends