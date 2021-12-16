#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int count(int a[],int n,int s)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<s+1;j++)
		{
			if(j>=a[i-1])
		    dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
		    else
		    dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][s];
}
int main()
{
	int i,a[1001],n,ans,s,j;
	cin>>n>>s;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<s+1;j++)
		{
			if(j==0)
			dp[i][j]=1;
			else
			{
				if(i==0)
				dp[i][j]=0;;
			}
		}
	}
	ans=count(a,n,s);
	cout<<ans<<endl;
}
