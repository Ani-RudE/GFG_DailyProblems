//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str)
    {
       int l = 0, r = str.size() - 1;
       
        while(true)
        {
            if(str[l] == str[r])
            {
                int n = (r - l) / 2;
                bool ok = true;
                for(int i = 0, j = r; i <= n; j--, i++)
                {
                    if(str[i] != str[j])
                    {
                        ok = false;
                        r = j;
                        break;
                    }
                }
                
                if(ok) return str.size() - r - 1;
            }
            else
            {
                r--;
            }
        } 
    }
};


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends