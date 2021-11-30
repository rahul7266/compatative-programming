#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s1,string s2,int n,int m)
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
}
int main()
{
	string ans;
	string s1,s2;
	cin>>s1>>s2;
	int i,j;
	for(i=0;i<s1.size()+1;i++)
	{
		for(j=0;j<s2.size()+1;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
		}
	}
	lcs(s1,s2,s1.size(),s2.size());
	i=s1.size();
	j=s2.size();
	while(i>=0&&j>=0)
	{
		if(s1[i-1]==s2[j-1])
		{
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j]>=dp[i][j-1])
			{
				ans.push_back(s1[i-1]);
				i--;
			}
			if(dp[i][j-1]>dp[i-1][j])
			{
				ans.push_back(s2[j-1]);
				j--;
			}
		}
	}
	
   for(i=ans.size()-1;i>=0;i--)
     cout<<ans[i]<<" ";	
}
