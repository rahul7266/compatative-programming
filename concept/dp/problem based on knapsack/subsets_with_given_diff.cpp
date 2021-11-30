#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int sub(int a[],int n,int s)
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
	int i,n,a[10001],dif,s=0,j,ts,ans;
	cin>>n>>dif;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	s=s+a[i];
	ts=(s+dif)/2;
//	cout<<ts<<endl;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<ts+1;j++)
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
	ans=sub(a,n,ts);
	cout<<ans<<endl;
}

