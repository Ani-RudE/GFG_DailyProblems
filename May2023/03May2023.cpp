//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     bool makePalindrome(int n, vector<string> &arr)
     {
          // Code here
          if (arr.size() == 2)
          {
               string a = arr[0];
               reverse(a.begin(), a.end());
               return a == arr[1];
          }

          if (arr[0].size() == 1 || arr[0].size() == 2)
          {
               unordered_map<string, int> ct;
               for (int i = 0; i < n; i++)
               {
                    ct[arr[i]]++;
               }
               for (auto x : ct)
               {
                    if (n % 2 == 0 && x.second % 2 != 0)
                         return false;
               }
          }

          multiset<string> s1;
          multiset<string> s2;
          for (int i = 0; i < n; i++)
          {
               string s = arr[i];
               s1.insert(s);
               reverse(s.begin(), s.end());
               s2.insert(s);
          }

          return s1 == s2;
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
          vector<string> arr(n);
          for (int i = 0; i < n; i++)
          {
               cin >> arr[i];
          }
          Solution ob;
          if (ob.makePalindrome(n, arr))
               cout << "YES" << endl;
          else
               cout << "NO" << endl;
     }
     return 0;
}
// } Driver Code Ends