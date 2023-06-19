//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int totalCuts(int N, int K, vector<int> &A)
     {
          int large[N];
          int small[N];
          int sm = 1000000, lg = 0;
          int ct = 0;
          
          for (int i = 0; i < N; i++)
          {
               if (A[i] > lg)
               {
                    lg = A[i];
               }
               large[i] = lg;
          }

          for (int i = N - 1; i >= 0; i--)
          {
               if (A[i] < sm)
               {
                    sm = A[i];
               }
               small[i] = sm;
          }

          for (int i = 0; i < N - 1; i++)
          {
               if (large[i] + small[i + 1] >= K)
               {
                    ct++;
               }
          }

          return ct;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int N, K;
          cin >> N >> K;
          vector<int> A(N);
          for (int i = 0; i < N; i++)
          {
               cin >> A[i];
          }
          Solution ob;
          cout << ob.totalCuts(N, K, A) << endl;
     }
     return 0;
}
// } Driver Code Ends