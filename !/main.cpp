//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

//} Driver Code Ends
//User function Template for C++
class Solution
{
public:
     int func(int n, int arr[])
     {
          //Code here
     }
};

//{ Driver Code Starts.

int main()
{

     int T;
     cin>>T;

     while(T--)
     {
          int n;
          cin>>n;
          int arr[n];
          for (int i=0; i<n; i++)
          {
               cin>>arr[i];
          }
          Solution ob;
          cout<<ob.func(n,arr);
     }
     return 0;
}
// } Driver Code Ends