#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int solve(int a[],int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i>=j)
    return 0;
    int mn=INT32_MAX;
    int k;
    int temp;
    for(k=i;k<=j-1;k++)
    {
    int l,r;
    if(dp[i][k]==-1)
     dp[i][k]=l=solve(a,i,k);
     else
     l=dp[i][k];
    if(dp[k+1][j]==-1) 
    dp[k+1][j]=r=solve(a,k+1,j);
    else
    r=dp[k+1][j];
      temp=l+r+a[i-1]*a[k]*a[j];
      if(temp<mn)
      {
         mn=temp;
      }
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int i,n,a[10001],ans;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    ans=solve(a,1,n-1);
   cout<<ans<<endl;
    return 0;
}
