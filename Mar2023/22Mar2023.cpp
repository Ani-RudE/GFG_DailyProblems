//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
     void rp(string s, int x, int y, long long &ans, bool flag)
     {
          string str;
          for (char c : s)
          {
               if (c == 'p')
               {
                    if (!str.empty() && str.back() == 'r')
                    {
                         ans += y;
                         str.pop_back();
                    }
                    else
                    {
                         str.push_back(c);
                    }
               }
               else
               {
                    str.push_back(c);
               }
          }
          if (flag)
          {
               pr(str, x, y, ans, false);
          }
     }

     void pr(string s, int x, int y, long long &ans, bool flag)
     {
          string str;
          for (char c : s)
          {
               if (c == 'r')
               {
                    if (!str.empty() && str.back() == 'p')
                    {
                         ans += x;
                         str.pop_back();
                    }
                    else
                    {
                         str.push_back(c);
                    }
               }
               else
               {
                    str.push_back(c);
               }
          }
          if (flag)
          {
               rp(str, x, y, ans, false);
          }
     }

     long long solve(int x, int y, string s)
     {
          long long ans = 0;
          if (x > y)
          {
               pr(s, x, y, ans, true);
          }
          else
          {
               rp(s, x, y, ans, true);
          }
          return ans;
     }
};

//{ Driver Code Starts.
signed main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int X, Y;
          cin >> X >> Y;
          string S;
          cin >> S;
          Solution obj;
          long long answer = obj.solve(X, Y, S);
          cout << answer << endl;
     }
}
// } Driver Code Ends