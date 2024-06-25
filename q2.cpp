#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
 class Node{
    Node * root=new Node(0);
    Node * left=root->left;
    Node * right=root->right;

 };
 vector<int>par;//(n,-1);
 void parent(Node * node, vector<int>&par,vector<int>&vis)
 {
    if(node==NULL) return;
    if(node->left && vis[node->left]==false)
    {
        par[node->left]=node;
    }
    if(node->right && vis[node->right]==false)
    par[node->right]=node;
 }
int f(int node,vector<int>&par,vector<int>&vis)
{
    queue<int>q;
    if(node==NULL) return NULL;
    q.push(node);
    vis[node]=true;
    while(!q.empty())
    {
        int si=q.size();
        for(int i=0;i<si;i++)
        {
            auto node1= q.front();
            q.pop();
            vis[node1]=true;
            if(!vis[node1->left])
            {
                vis[node1->left]=true;
                q.push(node1->left);
            }
            if(!vis[node1->right])
            {
                vis[node1->right]=true;
                q.push(node1->right);
            }
            if(par[node1]!=-1 && !vis[par[node]])
            {
                vis[par[node1]]=true;
                q.push(par[node1]);
            }


        }

    }
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; int a,b;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;

        }
    }
    return 0;
}