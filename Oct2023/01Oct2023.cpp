//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
     // Function to return list of integers that form the boundary
     // traversal of the matrix in a clockwise manner.
     vector<int> boundaryTraversal(vector<vector<int>> matrix, int r, int c)
     {
          vector<int> soln;

          if (r==1)
          {
               int i=0;
               while (i<c)
               {
                    soln.push_back(matrix[0][i]);
                    i++;
               }
          }
          else if (c==1)
          {
               int i=0;
               while (i<r)
               {
                    soln.push_back(matrix[i][0]);
                    i++;
               }
          }
          else
          {
               for (int j=0; j<c; j++) //First row
               {
                    soln.push_back(matrix[0][j]);
               }

               for (int j=1; j<=r-1; j++) //Last col except the last col element of first row
               {
                    soln.push_back(matrix[j][c-1]);
               }

               for (int j=c-2; j>=0; j--) //Last row except the last col element of last row
               {
                    soln.push_back(matrix[r-1][j]);
               }

               for (int j=r-2; j>0; j--) //First col except the first col element of last and first row
               {
                    soln.push_back(matrix[j][0]);
               }
          }

          return soln;
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