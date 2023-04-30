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
     int totalTime(int n, vector<int> &arr, vector<int> &time)
     {
          map<int, int> hm;
          vector<long long> cache(n);
          hm[arr[0]] = 0;
          cache[0] = 0;
          for (int i = 1; i < n; i++)
          {
               if (hm.count(arr[i]))
               {
                    long long currentTime = cache[i - 1] + 1;
                    long long previousTime = cache[hm[arr[i]]];
                    long long waited = currentTime - previousTime;
                    if (waited < time[arr[i] - 1])
                    {
                         currentTime += time[arr[i] - 1] - waited;
                    }
                    cache[i] = currentTime;
                    hm[arr[i]] = i;
               }
               else
               {
                    hm[arr[i]] = i;
                    cache[i] = cache[i - 1] + 1;
               }
          }
          return cache[n - 1];
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     scanf("%d ", &t);
     while (t--)
     {

          int n;
          scanf("%d", &n);

          vector<int> arr(n);
          Array::input(arr, n);

          vector<int> time(n);
          Array::input(time, n);

          Solution obj;
          int res = obj.totalTime(n, arr, time);

          cout << res << endl;
     }
}

// } Driver Code Ends