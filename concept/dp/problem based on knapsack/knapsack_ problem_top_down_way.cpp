#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(int val[],int wt[],int n,int size)
{
	int i ,j;
   for(i=1;i<n+1;i++)
   {
   	for(j=1;j<size+1;j++)
     	{
   	     if(j>=wt[i-1])	
   	     dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
   	     else
   	     dp[i][j]=dp[i-1][j];
        }
   }
   	return dp[n][size];
}
int main()
{
	int wt[1001],val[1001],n,i,size,ans;
	cin>>n>>size;
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=size;i++)
	   dp[0][i]=0;
	for(i=0;i<n;i++)
	cin>>wt[i];
	for(i=0;i<n;i++)
	cin>>val[i];
    ans=knapsack(val,wt,n,size);
    cout<<ans;	
}
