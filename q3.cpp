#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
bool check(vector<long long>arr,int  mid,long long m)
{
    int s=arr[0],cnt=1;
    for(int i=1;i<arr.size();i++)
    {
        if(s+arr[i]>mid)
        {
            cnt++;
            s=arr[i];
        }
        else
        s+=arr[i];
    }
    if(cnt<=m) return true;
    else
    return false;
}
int main()
{
    int t;
    cin>>t;
    vector< pair<vector<long long>,long long>>vec;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<long long>arr(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vec.push_back({arr,m});
    }
    vector<int>final;
for(auto it:vec)
{
    int s=*max_element(it.first.begin(),it.first.end());
    int e=0;
    for(auto i:it.first)
    e+=i;
int ans=INT_MAX;
long long m=it.second;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(check(it.first,mid,it.second))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else
        s=mid+1;
    }
    final.push_back(ans);
}
for(auto it:final)
cout<<it<<endl;
    return 0;
}