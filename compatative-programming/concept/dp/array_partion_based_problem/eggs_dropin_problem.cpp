#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int solve(int e,int f)
{
    if(dp[e][f]!=-1)
    return dp[e][f];
    int mx,ans=INT_MAX;
    if(e==1)
    return f;
    if(f==1)
    return 1;
    if(f==0)
    return 0;
    for(int i=1;i<=f;i++)
    {
        mx=1+max(solve(e-1,i-1),solve(e,f-i));
        ans=min(mx,ans);
    }
 return dp[e][f]=ans;   
}
int main()
{
memset(dp,-1,sizeof(dp));
int e,f;
cin>>e>>f;
cout<<solve(e,f);
}