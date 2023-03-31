//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
     string removeReverse(string S)
     {
          unordered_map<char, int> m;
          int n = S.length();

          for (auto it : S)
               m[it]++;

          int i = 0;

          int revCount = 0; // to count how many times we did reverse operation
          int counter = 1;
          while (i < S.length())
          {
               if (m[S[i]] > 1)
               {
                    m[S[i]]--;
                    revCount++;
                    S = S.substr(0, i) + S.substr(i + 1, S.length() - i - 1);

                    if (counter == 1)
                    {
                         i = S.length() - 1;
                         counter = -1;
                    }
                    else
                    {
                         i = 0;
                         counter = 1;
                    }
               }
               else
                    i += counter;
          }

          if (revCount % 2 == 0)
               return S;
          // else first reverse the string and then count
          reverse(S.begin(), S.end());
          return S;
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
          auto ans = obj.removeReverse(S);
          cout << ans << endl;
     }
}
// } Driver Code Ends