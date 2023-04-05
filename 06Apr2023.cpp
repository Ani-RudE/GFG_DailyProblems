//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
     template <class T>
     static void input(vector<T> &A, int n)
     {
          for (int i = 0; i < n; i++)
          {
               scanf("%d ", &A[i]);
          }
     }

     template <class T>
     static void print(vector<T> &A)
     {
          for (int i = 0; i < A.size(); i++)
          {
               cout << A[i] << " ";
          }
          cout << endl;
     }
};

// } Driver Code Ends
class Solution
{
public:
     int equalSum(int N, vector<int> &A)
     {
          int i, sum = 0, ls = 0, rs = 0;
          for (i = 0; i < N; i++)
          {
               sum = sum + A[i];
          }
          if (N == 1)
               return 1;
          for (i = 1; i < N; i++)
          {
               ls = ls + A[i - 1];
               rs = sum - ls - A[i];
               if (ls == rs)
               {
                    return i + 1;
               }
          }
          return -1;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     scanf("%d ", &t);
     while (t--)
     {

          int N;
          scanf("%d", &N);

          vector<int> A(N);
          Array::input(A, N);

          Solution obj;
          int res = obj.equalSum(N, A);

          cout << res << endl;
     }
}

// } Driver Code Ends