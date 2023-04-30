//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     vector<Node *> children;
     Node(int val)
     {
          data = val;
     }
};

class N_ary_Tree
{
public:
     Node *root;
     int size;
     N_ary_Tree()
     {
          root = NULL;
          size = 0;
     }
     Node *add(int new_key, Node *parent_key = NULL)
     {
          Node *new_node = new Node(new_key);
          if (parent_key == NULL)
          {
               root = new_node;
               size = 1;
          }
          else
          {
               parent_key->children.push_back(new_node);
               size += 1;
          }
          return new_node;
     }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     unordered_map<string, int> map;

     string solve(Node *root)
     {

          if (root == NULL)
          {
               return "";
          }
          
          int val = root->data;
          string ans = to_string(val);
          for (int i = 0; i < root->children.size(); i++)
          {
               ans += solve(root->children[i]);
               ans += "_";
          }

          map[ans]++;
          return ans;
     }
     int duplicateSubtreeNaryTree(Node *root)
     {
          if (root == NULL)
          {
               return 0;
          }
          solve(root);

          int count = 0;
          for (auto i : map)
          {
               if (i.second > 1)
                    count++;
          }

          return count;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     for (int i = 0; i < t; i++)
     {
          if (i == 0)
          {
               string p;
               getline(cin, p);
          }
          string str;
          getline(cin, str);
          stringstream st(str);
          vector<string> s;
          string y;
          while (st >> y)
          {
               s.push_back(y);
          }
          N_ary_Tree *tree = new N_ary_Tree();
          Node *curr;
          queue<Node *> q;
          for (int i = 0; i < s.size(); i++)
          {
               if (i == 0)
               {
                    curr = tree->add(stoi(s[0]));
               }
               else if (s[i] == " ")
               {
                    continue;
               }
               else if (q.size() and s[i] == "N")
               {
                    curr = q.front();
                    q.pop();
               }
               else if (s[i] != "N")
               {
                    q.push(tree->add(stoi(s[i]), curr));
               }
          }
          Solution ob;
          int res = ob.duplicateSubtreeNaryTree(tree->root);
          cout << res << endl;
     }
}
// } Driver Code Ends