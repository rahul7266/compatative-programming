//can a array be divded into two sets of equal sum or not
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int equalsum(int a[],int s,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=s;j++)
		{
			if(a[i-1]<=j)
				dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][s];
}
int main()
{
	int a[10001],n,i,s=0,j;
	cin>>n;
	 for(i=0;i<n;i++)
    	cin>>a[i];
	for(i=0;i<n;i++)
    	s=s+a[i];
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<s+1;j++)
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
   	
	if(s%2!=0)
	cout<<"No"<<endl;
	else
	{
		if(equalsum(a,s/2,n))
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
}
