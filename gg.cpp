//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
     // Function to return list of integers that form the boundary
     // traversal of the matrix in a clockwise manner.
     vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
     {
          for (int i = 0; i < n; i++)
          {
          }
     }
};

//{ Driver Code Starts.
int main()
{
     int t;
     cin >> t;

     while (t--)
     {
          int n, m;
          cin >> n >> m;
          vector<vector<int>> matrix(n);

          for (int i = 0; i < n; i++)
          {
               matrix[i].assign(m, 0);
               for (int j = 0; j < m; j++)
               {
                    cin >> matrix[i][j];
               }
          }

          Solution ob;
          vector<int> result = ob.boundaryTraversal(matrix, n, m);
          for (int i = 0; i < result.size(); ++i)
               cout << result[i] << " ";
          cout << endl;
     }
     return 0;
}
// } Driver Code Ends