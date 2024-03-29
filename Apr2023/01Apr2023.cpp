//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     long long int minOperations(int n)
     {

          if (n == 1)
               return 0;
          if (n % 2 == 1)
          {
               long long int no = (long long)(n) / (long long)(2);
               return (long long)(no) * ((long long)(no) + (long long)(1));
          }
          else
          {
               long long int no = ((long long)(n) - (long long)(1)) / (long long)(2);
               return ((long long)(n) / (long long)(2)) + (long long)(no) * ((long long)(no) + (long long)(1));
          }
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
          Solution ob;
          cout << ob.minOperations(n) << endl;
     }
     return 0;
}
// } Driver Code Ends