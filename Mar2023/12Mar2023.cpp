//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
     public:
     vector<int> findMaxRow(vector<vector<int>> mat, int N)
     {
          //code here
          int i=0;
          int j=N-1;
        
        
          int row=0;
          int one_count=0;
          while(j>=0 and i<N)
          {
               if(mat[i][j]==1)
               {
                    one_count++;
                    row=i;
                    j--;
               }
               else
               {
                    i++;
               }
          }

          vector<int>ans;
          ans.push_back(row);
          ans.push_back(one_count);

          return ans;
     }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends





// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//      int n=3;
//      int m[n][n]={{0, 0, 1}, 
//                   {0, 1, 1}, 
//                   {0, 0, 0}};

//      int r=0, count=0, max=0, rownum=0;

//      for (int c=0; c<n; c++)
//      {
//           if (m[c][r]==1)
//           {
//                count=count+1;
//                if (count>max)
//                {
//                     rownum=r;
//                     max=count;
//                     count=0;
//                }
//           }

//           r+=1;
//      }

//      cout<<"Row Number: "<<rownum<<endl;
//      cout<<"Max Count: "<<max;

//      return 0;
// }