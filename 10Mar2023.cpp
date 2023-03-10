//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	long long int a=arr[0];
    	long long int b=arr[1];
    	long long int c=arr[n-1];
    	long long int d=arr[n-2];
    	long long int e=arr[n-3];
    	long long int f=a*b*c;
    	long long int g=c*d*e;
    	return max(f,g);
    	
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends