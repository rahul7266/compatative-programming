//length of min possible supersequence made from two strings, that contains both of those string(could be non-continues) hint-- m+n-len(lcs)
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int super(string s1,string s2,int n,int m)
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
	string s1,s2;
	int i,j,lcs;
	cin>>s1>>s2;
	for(i=0;i<s1.size()+1;i++)
	{
		for(j=0;j<s2.size()+1;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
		}
	}
   lcs=super(s1,s2,s1.size(),s2.size());
   cout<<s1.size()+s2.size()-lcs<<endl;
} 
