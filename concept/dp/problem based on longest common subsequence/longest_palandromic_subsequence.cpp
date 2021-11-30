//len of longest palandromic subsquence
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int pal(string s1,string s2,int n,int m)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
		if(s1[i-1]==s2[j-1])
		dp[i][j]=dp[i-1][j-1]+1;
		else
		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);	
		}
	}
	return dp[n][m];
}
int main()
{
	int i,j;
	string s1,s2;
	cin>>s1;
	for(i=s1.size()-1;i>=0;i--)
	{
		s2.push_back(s1[i]);
	}
	for(i=0;i<s1.size()+1;i++)
	{
		for(j=0;j<s2.size()+1;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
		}
	}
	cout<<pal(s1,s2,s1.size(),s2.size());
	
}
