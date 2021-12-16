#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int subset(int a[],int n,int sum)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(j>=a[i-1])
			dp[i][j]=(dp[i-1][j-a[i-1]]||dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int main()
{
	int n,sum,i,a[10001],j,ans;
	cin>>n>>sum;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<sum+1;j++)
		{
		if(j==0)
		dp[i][j]=1;
		else
		{
			if(i==0)
			dp[i][j]=0;
		}
        }
	}
	ans=subset(a,n,sum);
	if(ans)
	cout<<"yes"<<endl;
	else
	cout<<"NO"<<endl;
}
