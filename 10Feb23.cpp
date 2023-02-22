//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int b=0, a=0, l=0, o=0, n=0;
        int ans;
        
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='b')
            {
                b++;
            }
            else if (s[i]=='a')
            {
                a++;
            }
            else if (s[i]=='l')
            {
                l++;
            }
            else if (s[i]=='o')
            {
                o++;
            }
            else if (s[i]=='n')
            {
                n++;
            }
        }
        
        if (l%2==0)
        {
            l=l/2;
        }
        else
        {
            l=(l-1)/2;
        }
        
        if (o%2==0)
        {
            o=o/2;
        }
        else
        {
            o=(o-1)/2;
        }
        
        ans=min(b, a);
        ans=min(ans, l);
        ans=min(ans, o);
        ans=min(ans, n);
    
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0
}
// } Driver Code Ends