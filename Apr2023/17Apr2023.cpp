//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
     int id;     // Job Id
     int dead;   // Deadline of job
     int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
     // Function to find the maximum profit and the number of jobs done.
     vector<int> JobScheduling(Job arr[], int n)
     {
          priority_queue<pair<int, int>> pq;
          for (int i = 0; i < n; i++)
          {
               pq.push({arr[i].profit, arr[i].dead});
          }
          vector<bool> v1(100000, false);
          int ans = 0, count = 0;

          while (pq.size() > 0)
          {
               bool flag = false;
               for (int i = pq.top().second; i > 0; i--)
               {
                    // cout<<pq.top().first<<" "<<pq.top().second<<endl;
                    if (v1[i] == false)
                    {
                         ans += pq.top().first;
                         count++;
                         //  cout<<i<<endl;
                         v1[i] = true;
                         break;
                    }
               }
               pq.pop();
          }

          return {count, ans};
     }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
     int t;
     // testcases
     cin >> t;

     while (t--)
     {
          int n;

          // size of array
          cin >> n;
          Job arr[n];

          // adding id, deadline, profit
          for (int i = 0; i < n; i++)
          {
               int x, y, z;
               cin >> x >> y >> z;
               arr[i].id = x;
               arr[i].dead = y;
               arr[i].profit = z;
          }
          Solution ob;
          // function call
          vector<int> ans = ob.JobScheduling(arr, n);
          cout << ans[0] << " " << ans[1] << endl;
     }
     return 0;
}

// } Driver Code Ends