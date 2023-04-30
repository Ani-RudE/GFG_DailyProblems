//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     vector<int> nearestSmallerTower(vector<int> a)
     {
          // code here
          int n = a.size();
          int l[n], r[n];

          // initialising left and right array which contains smaller values to left and right respectively
          l[0] = -1;
          r[n - 1] = -1;

          // iterating for left side values
          for (int i = 1; i < n; i++)
          {
               if (a[i - 1] < a[i])
                    l[i] = i - 1;
               else
               {
                    int j = i - 1;
                    while (j >= 0)
                    {
                         if (a[i] > a[l[j]])
                         {
                              l[i] = l[j];
                              break;
                         }
                         j--;
                    }
                    if (j == n)
                         r[i] = -1;
               }
          }

          // iterating for right side values
          for (int i = n - 2; i >= 0; i--)
          {
               if (a[i] > a[i + 1])
                    r[i] = i + 1;
               else
               {
                    int j = i + 1;
                    while (j < n)
                    {
                         if (a[i] > a[r[j]])
                         {
                              r[i] = r[j];
                              break;
                         }
                         j++;
                    }
                    if (j == n)
                         r[i] = -1;
               }
          }

          vector<int> res(n);
          res[0] = max(l[0], r[0]);
          res[n - 1] = max(l[n - 1], r[n - 1]);

          // choosing value among left and rigth based on condition
          for (int i = 1; i < n - 1; i++)
          {
               if (min(l[i], r[i]) < 0)
                    res[i] = max(l[i], r[i]);
               else
               {
                    int ld = i - l[i];
                    int rd = r[i] - i;
                    if (ld == rd)
                    {
                         if (a[r[i]] > a[l[i]])
                              res[i] = l[i];
                         else if (a[l[i]] > a[r[i]])
                              res[i] = r[i];
                         else
                              res[i] = min(l[i], r[i]);
                    }
                    else
                    {
                         if (ld > rd)
                              res[i] = r[i];
                         else
                              res[i] = l[i];
                    }
               }
          }

          return res;
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
          vector<int> v(n);
          for (int i = 0; i < n; i++)
          {
               cin >> v[i];
          }
          Solution ob;
          vector<int> ans = ob.nearestSmallerTower(v);
          for (int i = 0; i < n; i++)
          {
               cout << ans[i] << " ";
          }
          cout << "\n";
     }
     return 0;
}
// } Driver Code Ends