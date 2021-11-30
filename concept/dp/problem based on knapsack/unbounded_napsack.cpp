//unbounded napsack---one item can be picked many times
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(int wt[],int val[],int n,int w)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<w+1;j++)
		{
			if(wt[i-1]<=j)
			dp[i][j]=max(dp[i][j-wt[i-1]]+val[i-1],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}
int main()
{
	int wt[10001],val[10001],n,i,w,j,ans;
	cin>>n>>w;
	for(i=0;i<n;i++)
	cin>>wt[i];
	for(i=0;i<n;i++)
	cin>>val[i];
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<w+1;j++)
		{
			if(j==0||i==0)
			dp[i][j]=0;
		}
	}
	ans=knapsack(wt,val,n,w);
	cout<<ans<<endl;
}
