//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int countSpecialNumbers(int N, vector<int> arr)
     {
          int count=0, x=INT_MAX;

          sort(arr.begin(), arr.end());

          for (int i=0; i<N; i++)
          {
               x=INT_MAX;

               if(arr[i]==-1)
                    continue;

               for (int j=i+1; j<N; j++)
               {
                    if (arr[j]%arr[i]==0)
                    {
                         count++;
                         x=min(x, arr[j]);
                         arr[j]=-1;
                    }
               }

               if (arr[i]==x)
                    count++;
          }

          return count;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int N;
          cin >> N;
          vector<int> arr(N);
          for (int i = 0; i < N; i++)
          {
               cin >> arr[i];
          }

          Solution ob;
          cout << ob.countSpecialNumbers(N, arr) << endl;
     }
     return 0;
}
// } Driver Code Ends