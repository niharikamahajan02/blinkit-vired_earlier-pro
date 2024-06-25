#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
int maximize(vector<int>&coins)
{
    int sum=0; int maxi=INT_MIN;
    for(int i=0;i<coins.size();i++)
    {
        sum+=coins[i];
        maxi=max(maxi,sum);
        if(sum<0)
        sum=0;
    }
    return maxi;
}

int main()
{
   int t;
    cin>>t;
    vector<vector<int>>vec;
   
   int test=t;
    
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>coins(n,0);
       
        for(int i=0;i<n;i++)
        {
            cin>>coins[i];
        }
        vec.push_back(coins);

    }
 
  for(auto it:vec)
  {
    cout<<maximize(it)<<endl;
  }
  
  return 0;

}