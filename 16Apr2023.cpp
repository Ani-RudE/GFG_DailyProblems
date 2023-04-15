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

#define ll long long
class Solution
{
public:
     ll solve(int n, vector<int> &a, vector<int> &b)
     {
          vector<vector<int>> frqA(2), frqB(2);
          ll sum = 0, ans = 0;
          for (int i = 0; i < n; i++)
          {
               sum += (a[i] - b[i]);
               frqA[abs(a[i]) % 2].push_back(a[i]);
               frqB[abs(b[i]) % 2].push_back(b[i]);
          }
          if (sum != 0 || frqA[0].size() != frqB[0].size() || frqA[1].size() != frqB[1].size())
               return -1;
          for (int i = 0; i < 2; i++)
          {
               sort(frqA[i].begin(), frqA[i].end());
               sort(frqB[i].begin(), frqB[i].end());
               for (int j = 0; j < frqA[i].size(); j++)
                    ans += abs(frqA[i][j] - frqB[i][j]) / 2;
          }
          
          return ans / 2;
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

          vector<int> B(N);
          Array::input(B, N);

          Solution obj;
          long long res = obj.solve(N, A, B);

          cout << res << endl;
     }
}

// } Driver Code Ends