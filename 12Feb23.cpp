//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
        Node*temp=head;
        int maxi =INT_MIN;
        if(head==NULL)return head;
        while(temp!=NULL){
            maxi=max(temp->val,maxi);
            temp=temp->next;
        }
        
        vector<int>v(100000,1);
        v[1]=0;
        for(int i =1;i*i<100000;i++){
            if(v[i]==1){
                for(int j =i*i;j<100000;j+=i){
                    v[j]=0;
                }
            }
        }
        int final = maxi ;
        while(v[final]!=1){
            if(v[final]==1){
                break;
            }
            else{
                final++;
            }
        }
        
        temp =head;
        Node*anss=temp;
        while(temp!=NULL){
            if(v[temp->val]==1){
                temp=temp->next;
            }
            else{
                int l=temp->val;
                int r=temp->val;
                bool y = true;
                while(l>=2 || r<=final){
                    l--;
                    r++;
                    if(l>=2){
                        if(v[l]==1){
                        temp->val=l;
                        y=false;
                        break;
                    }
                    }
                    if(r<=final){
                        if(v[r]==1){
                        temp->val=r;
                        y=false;
                        break;
                    }
                    }
                    
                   if(y==false)break;
                }
                temp=temp->next;
                
            }
        }
        
        return anss;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0
}
// } Driver Code Ends