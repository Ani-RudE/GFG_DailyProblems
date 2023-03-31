//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
     char data;
     struct Node *next;

     Node(char x)
     {
          data = x;
          next = NULL;
     }
};

void printList(Node *node)
{
     while (node != NULL)
     {
          cout << node->data << " ";
          node = node->next;
     }
     cout << endl;
}

struct Node *inputList()
{
     int n; // length of link list
     scanf("%d ", &n);

     char data;
     cin >> data;
     struct Node *head = new Node(data);
     struct Node *tail = head;
     for (int i = 0; i < n - 1; ++i)
     {
          cin >> data;
          tail->next = new Node(data);
          tail = tail->next;
     }
     return head;
}

// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution
{
public:
     vector<Node *> findAnagrams(struct Node *head, string s)
     {

          unordered_map<char, int> m;
          vector<Node *> res;
          for (int i = 0; i < s.size(); i++)
          {
               m[s[i]]++;
          }

          int count1 = m.size();
          Node *temp = head;
          Node *prev = NULL;
          Node *itr = head;

          int count = 0;

          while (count < s.size())
          {
               if (m.find((*itr).data) != m.end())
               {

                    m[(*itr).data]--;
                    if (m[(*itr).data] == 0)
                    {
                         count1--;
                    }
               }

               prev = itr;
               itr = (*itr).next;
               count++;
          }

          while (itr != NULL)
          {

               if (count1 == 0)
               {
                    (*prev).next = NULL;
                    res.push_back(temp);
                    temp = itr;
                    count = 0;
                    for (int i = 0; i < s.size(); i++)
                    {
                         m[s[i]]++;
                    }

                    count1 = m.size();
                    while (count < s.size() && itr != NULL)
                    {
                         if (m.find((*itr).data) != m.end())
                         {
                              m[(*itr).data]--;
                              if (m[(*itr).data] == 0)
                              {
                                   count1--;
                              }
                         }

                         prev = itr;
                         itr = (*itr).next;
                         count++;
                    }
               }
               else
               {

                    if (m.find((*temp).data) != m.end())
                    {
                         m[(*temp).data]++;
                         if (m[(*temp).data] == 1)
                         {
                              count1++;
                         }
                    }

                    if (m.find((*itr).data) != m.end())
                    {
                         m[(*itr).data]--;
                         if (m[(*itr).data] == 0)
                         {
                              count1--;
                         }
                    }

                    temp = (*temp).next;
                    prev = itr;
                    itr = (*itr).next;
               }
          }

          if (count1 == 0)
          {
               (*prev).next = NULL;
               res.push_back(temp);
          }

          return res;
     }
};

//{ Driver Code Starts.

int main()
{
     int t;
     cin >> t;
     while (t--)
     {

          struct Node *head = inputList();

          string s;
          cin >> s;

          Solution obj;
          vector<Node *> res = obj.findAnagrams(head, s);

          for (int i = 0; i < res.size(); i++)
          {
               printList(res[i]);
          }

          if (res.size() == 0)
               cout << "-1\n";
     }
}

// } Driver Code Ends