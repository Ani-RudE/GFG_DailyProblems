//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        long long int count=0;
        long long int rem;
        unsigned long long int power;
        long long int bin=0, x=0;
        
        while (N!=0)
        {
            rem=N%2;
            power=pow(10, x);
            bin=(power*rem)+bin;
            N=N/2;
            x++;
            
            if (rem==1)
                count++;
        }

        //This part was not really needed in the answer
        // string num=to_string(bin);
        
        // for (int i=0; i<num.size(); i++)
        // {
        //     if (num[i]=='1')
        //         count++;
        // }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends