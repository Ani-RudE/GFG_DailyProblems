#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
     {
          unordered_map<int, int> row, col;

          vector<long long int> ans;

          for (int i = 0; i < k; i++)

          {

               row[arr[i][0]]++;

               col[arr[i][1]]++;

               int r = row.size(), c = col.size();

               long long int t = n * n - (r * n + c * n - r * c);

               ans.push_back(t);
          }

          return ans;
     }
};

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int n, k;
          cin >> n >> k;
          vector<vector<int>> arr(k, vector<int>(2));
          for (int i = 0; i < k; i++)
          {
               int x, y;
               cin >> x >> y;
               arr[i][0] = x;
               arr[i][1] = y;
          }
          Solution ob;
          vector<long long int> ans = ob.countZero(n, k, arr);

          for (int i = 0; i < ans.size(); i++)
          {
               cout << ans[i] << " ";
          }
          
          cout << endl;
     }

     return 0
}