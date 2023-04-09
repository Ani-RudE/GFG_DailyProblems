//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int maxIntersections(vector<vector<int>> lines, int N)
     {

          map<int, int> m;

          for (int i = 0; i < N; i++)
          {
               m[lines[i][0]]++;
               m[lines[i][1] + 1]--;
          }

          int ans = 0;
          int sum = 0;

          for (auto it : m)
          {
               sum += it.second;
               ans = max(ans, sum);
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
          int N;
          cin >> N;
          vector<vector<int>> mat(N, vector<int>(2));
          for (int j = 0; j < 2; j++)
          {
               for (int i = 0; i < N; i++)
               {
                    cin >> mat[i][j];
               }
          }
          Solution obj;
          cout << obj.maxIntersections(mat, N) << endl;
     }
}
// } Driver Code Ends