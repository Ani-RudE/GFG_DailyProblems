//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        int n=A+C;
        int i=1;
        
        while (n<=B)
        {
            if (n==B)
            {
                return i;
            }
            
            n+=C;
            i++;
        }
        
        return 0;
        //     if (n>B)
        //     {
        //         return 0;
        //     }
        //     else if (n==B)
        //     {
        //         return i;
        //     }
        //     n=n+C;
        // }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends