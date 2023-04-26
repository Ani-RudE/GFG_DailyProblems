//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
     public:
     bool is_possible_to_get_seats(int n, int m, vector<int> &seats)
     {
          vector<int> vis(m, 0);
          
          for (int i = 0; i < m; i++)
          {
               if (seats[i] == 1)
               {
                    if (i != 0)
                    {
                         vis[i - 1] = 1;
                    }
                    if (i != m - 1)
                    {
                         vis[i + 1] = 1;
                    }
                    vis[i] = 1;
               }
          }

          int s = 0;
          int ans = 0;

          for (int i = 0; i < m; i++)
          {
               if (vis[i] == 0)
               {
                    s++;
               }
               else
               {
                    if (s % 2 == 0)
                    {
                         ans += s / 2;
                    }
                    else
                    {
                         ans += s / 2 + 1;
                    }
                    s = 0;
               }
          }

          if (s >= 1)
          {
               if (s % 2 == 0)
               {
                    ans += s / 2;
               }
               else
               {
                    ans += s / 2 + 1;
               }
          }

          return ans >= n;
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
          int m;
          cin >> m;
          vector<int> seats(m);
          for (int i = 0; i < m; i++)
          {
               cin >> seats[i];
          }
          Solution obj;
          if (obj.is_possible_to_get_seats(n, m, seats))
          {
               cout << "Yes" << endl;
          }
          else
          {
               cout << "No" << endl;
          }
     }
}

// } Driver Code Ends