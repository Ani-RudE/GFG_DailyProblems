//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
     template <class T>
     static void input(vector<T> &A, int n)
     {
          for (int i = 0; i < n; i++)
          {
               scanf("%d ", &A[i]);
          }
     }

     template <class T>
     static void print(vector<T> &A)
     {
          for (int i = 0; i < A.size(); i++)
          {
               cout << A[i] << " ";
          }
          cout << endl;
     }
};

// } Driver Code Ends
// class Solution
// {
// public:
//      int getMinimumDays(int N, string S, vector<int> &P)
//      {
//           // code here
//           int k=0;
//           vector<int>::iterator itr;

//           for (int i=0; i<N; i++)
//           {
//                if (S[i]!='?' && S[i]==S[i+1])
//                {
//                     S[P[k]]='?';
//                     k+=1;
//                }
//           }

//           for (itr=P.begin(); itr!=P.end(); itr++)
//           {
//                cout<<*itr<<" ";
//           }
//           cout<<endl;
          
//           return k-1;
//      }
// };

class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
         int j=0;

        for(int i=0;i<N;i++)

        {

            while(S[i]==S[i+1]&&S[i]!='?'){

                S[P[j]]='?';

                j++;

            }

        }

        return j;
    }
};

// Driver Code Starts.

int main()
{
     int t=1;
     scanf("%d ", &t);
     while (t--)
     {

          int N;
          scanf("%d", &N);
          string S;
          cin >> S;

          vector<int> P;
          Array::input(P, N);
          cout<<endl;

          Solution obj;
          int res = obj.getMinimumDays(N, S, P);

          cout << res << endl;
     }
}

// } Driver Code Ends