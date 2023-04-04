//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int minSteps(string str)
{
     int c = 0, i = 1;
     while (str[i] != '\0')
     {
          if (str[i] != str[i - 1])
          {
               c++;
          }
          i++;
     }
     c++;
     return ((c / 2) + 1);
}

//{ Driver Code Starts.

int main()
{

     int t;
     cin >> t;
     while (t--)
     {
          string str;
          cin >> str;
          cout << minSteps(str) << endl;
     }
}

// } Driver Code Ends