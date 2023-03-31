//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     string secondSmallest(int S, int D)
     {
          vector<int> d(D, 0);
          vector<int> v(10, 0);
          if (S < 2 || S > (9 * D - 1) || D == 1)
               return "-1";
          int s = S - 1;
          for (int i = 9; i >= 1; i--)
          {
               v[i] = s / i;
               s %= i;
          }
          int j = D - 1;
          for (int i = 9; i >= 1; i--)
          {
               for (int k = v[i]; k > 0; k--)
               {
                    d[j--] = i;
               }
          }
          d[0] += 1;
          j = D - 1;
          while ((d[j] <= d[j - 1]) && j > 1)
               j--;
          d[j] -= 1;
          d[j - 1] += 1;
          string st = "";
          for (int i = 0; i < D; i++)
          {
               st += to_string(d[i]);
          }
          return st;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int S, D;
          cin >> S >> D;
          Solution ob;
          cout << ob.secondSmallest(S, D) << endl;
     }
     return 0;
}
// } Driver Code Ends