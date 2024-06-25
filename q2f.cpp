#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#include<queue>
using namespace std;
int f(vector<int>adj[],int i)
{
   queue<int>q;
   q.push(i);
   

}
int main()
{
    int t;
    cin>>t;
    //vector< vector<int>adj[]>adj_f;
    //while(t--)
    //{
        int n;
        cin>>n; int a,b;
        vector<int>adj[1000];
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
        }
       // adj_f.push_back(adj);
    //}
    for(int i=1;i<n;i++)
    {
    int ans=f(adj,i);

    }
    return 0;
}