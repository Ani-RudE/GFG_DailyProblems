//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     Node *left;
     Node *right;

     Node(int val)
     {
          data = val;
          left = NULL;
          right = NULL;
     }

     Node *buildTree(string s)
     {
          if (s.length() == 0 || s[0] == 'N')
               return NULL;

          // Create the root of the tree
          vector<string> str;
          istringstream iss(s);
          for (string s; iss >> s;)
               str.push_back(s);
          Node *root = new Node(stoi(str[0]));

          // Push the root to the queue
          queue<Node *> q;
          q.push(root);

          // Starting from the second element
          int i = 1;
          while (q.size() > 0 && i < str.size())
          {

               // Get and remove the front of the queue
               Node *currNode = q.front();
               q.pop();

               // Get the current node's value from the string
               string currVal = str[i];

               // If the left child is not null
               if (currVal != "N")
               {

                    // Create the left child for the current node
                    currNode->left = new Node(stoi(currVal));
                    // Push it to the queue
                    q.push(currNode->left);
               }

               // For the right child
               i++;
               if (i >= str.size())
                    break;

               currVal = str[i];

               // If the right child is not null
               if (currVal != "N")
               {

                    // Create the right child for the current node
                    currNode->right = new Node(stoi(currVal));

                    // Push it to the queue
                    q.push(currNode->right);
               }
               i++;
          }

          return root;
     }

     void inorder(Node *root)
     {
          if (root == NULL)
               return;
          inorder(root->left);
          cout << root->data << " ";
          inorder(root->right);
     }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
     int minSubtreeSumBST(int target, Node *root)
     {
          int min_length = INT_MAX;
          dfs(root, target, min_length);
          return min_length == INT_MAX ? -1 : min_length;
     }

     void dfs(Node *node, int target, int &min_length)
     {
          if (node == nullptr)
          {
               return;
          }

          int sum = computeSum(node);
          if (sum == target && isBST(node))
          {
               int length = computeLength(node);
               min_length = min(min_length, length);
          }

          dfs(node->left, target, min_length);
          dfs(node->right, target, min_length);
     }

     int computeSum(Node *node)
     {
          if (node == nullptr)
          {
               return 0;
          }

          return node->data + computeSum(node->left) + computeSum(node->right);
     }

     bool isBST(Node *node)
     {
          vector<int> nodes;
          inorder(node, nodes);
          for (int i = 1; i < nodes.size(); i++)
          {
               if (nodes[i] <= nodes[i - 1])
               {
                    return false;
               }
          }
          return true;
     }

     void inorder(Node *node, vector<int> &nodes)
     {
          if (node == nullptr)
          {
               return;
          }

          inorder(node->left, nodes);
          nodes.push_back(node->data);
          inorder(node->right, nodes);
     }

     int computeLength(Node *node)
     {
          if (node == nullptr)
          {
               return 0;
          }

          return 1 + computeLength(node->left) + computeLength(node->right);
     }
};

//{ Driver Code Starts.

int main()
{

     int t;
     cin >> t;
     while (t--)
     {
          int target;
          cin >> target;
          string str;
          getline(cin, str);
          getline(cin, str);
          Node node(0);
          Node *root = node.buildTree(str);
          Solution ob;
          int res = ob.minSubtreeSumBST(target, root);
          cout << res << endl;
     }
     return 0;
}
// } Driver Code Ends