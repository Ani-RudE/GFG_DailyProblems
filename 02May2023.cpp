//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     bool check(vector<int> &arr, int mid, int k)
     {
          int n = arr.size();
          int cnt = 0;
          long long sum = 0;
          
          for (int i = 0; i < n; i++)
          {
               sum += arr[i];

               if (sum >= mid)
               {
                    sum = 0;
                    cnt++;
               }
          }

          return cnt >= k + 1;
     }

     int maxSweetness(vector<int> &sweetness, int N, int K)
     {
          long long l = 0, r = accumulate(sweetness.begin(), sweetness.end(), 0ll);

          while (l < r)
          {
               long long mid = l + r + 1 >> 1;

               if (check(sweetness, (int)mid, K))
                    l = mid;
               else
                    r = mid - 1;
          }

          return (int)l;
     }
};

//{ Driver Code Starts.

int main()
{

     int t;
     cin >> t;
     while (t--)
     {
          int n, k;
          cin >> n >> k;
          vector<int> sweetness(n);
          for (int i = 0; i < n; i++)
          {
               cin >> sweetness[i];
          }
          Solution ob;
          int res = ob.maxSweetness(sweetness, n, k);
          cout << res << endl;
     }
}
// } Driver Code Ends