//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        int minv=INT_MAX;
        long long int sticks,ans=0;
        
        for(int i=0;i<N;i++)
        {
            int cnt=B[i];
            
            if(cnt%2!=0)
                cnt-=1;
            if(cnt>=2)
                minv=min(minv,A[i]);
                
            ans+=(cnt*A[i]);
            sticks+=cnt;
        }
        
        if(sticks%4!=0)
        {
            ans-=(2*minv);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends