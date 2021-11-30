//divide array in two subset such that their sum diffrence is min output ---min diff
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void sum(int a[],int n,int s)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<s+1;j++)
		{
			if(j>=a[i-1])
			dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
}
int main()
{
	int a[1000],i,n,s=0,j,s1;
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
   sum(a,n,s);
   s1=1001110;
   for(i=0;i<s+1;i++)
   {
   	if(dp[n][i])
   	s1=min(s1,abs(s-2*i));
   }
   cout<<s1<<endl;
}
