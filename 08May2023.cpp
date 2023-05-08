//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int modulo(string s, int m)
     {
          int decValue = 0;
          int base = 1;
          int j = s.length() - 1;

          while (j >= 0)
          {
               if (s[j] == '1')
               {
                    // including base
                    decValue += base;
               }
               // we will mod side by side to prevent integer overflow
               decValue %= m;
               base *= 2;
               base %= m;
               j--;
          }

          return decValue;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          string s;
          int m;
          cin >> s >> m;
          Solution a;
          cout << a.modulo(s, m) << endl;
     }
     return 0;
}
// } Driver Code Ends