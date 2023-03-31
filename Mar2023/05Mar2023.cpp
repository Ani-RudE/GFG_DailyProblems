//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int find_set(int v,int parent[])
{
    if(v==parent[v])
        return v;
    
    return parent[v]=find_set(parent[v],parent);
}

bool isConnected(int u,int v, int par[], int rank1[])
{

    int x=find_set(u,par);
    int y=find_set(v,par);
        
    return x==y;
}

void union_(int a, int b, int par[], int rank1[])
{
    a=find_set(a,par);
    b=find_set(b,par);
    if(a!=b)
    {
        if(rank1[a]<rank1[b])
        swap(a,b);
        rank1[a]+=rank1[b];
        par[b]=a;
    }

}

void copy(int arr[],int arr2[],int n)
{
    for(int i=0;i<n;i++)
        arr2[i]=arr[i];
}

class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,vector<vector<int>> danger, int m)
    {
        int rank1[n];
        int temprank1[n];
        int par[n];
        int temppar[n];
        vector<string>ans(n,"Yes");
        memset(rank1,1,sizeof(int)*n);
        memset(temprank1,1,sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            par[i]=i;temppar[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            int flag=1;
            union_(mix[i][0]-1,mix[i][1]-1,temppar,temprank1);
            
            for(int j=0;j<m;j++)
            {
                if(isConnected(danger[j][0]-1,danger[j][1]-1,temppar,temprank1))
                {
                    flag=0;break;
                }
            }
            
            if(flag)
            {
                copy(temppar,par,n);
                copy(temprank1,rank1,n);
            }
            else
            {
                ans[i]="No";
                copy(par,temppar,n);
                copy(rank1,temprank1,n);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends