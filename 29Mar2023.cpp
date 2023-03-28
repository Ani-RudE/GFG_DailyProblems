//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
     int countSubstring(string S)
     {
          int i, j, p, q, k = 0, n = S.size();
          for (i = 0; i < n; i++)
          {
               p = 0;
               q = 0;
               for (j = i; j < n; j++)
               {
                    if (S[j] >= 'a' && S[j] <= 'z')
                         p++;
                    if (S[j] >= 'A' && S[j] <= 'Z')
                         q++;
                    if (p == q)
                         k++;
               }
          }
          return k;
     }
};

//{ Driver Code Starts.
int main()
{

     int t;
     cin >> t;
     while (t--)
     {
          string S;
          cin >> S;
          Solution obj;
          cout << obj.countSubstring(S) << endl;
     }
}
// } Driver Code Ends