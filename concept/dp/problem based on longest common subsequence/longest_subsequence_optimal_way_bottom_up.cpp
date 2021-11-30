#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int sub(string s1,string s2,int n,int m)
{
	if(n==0||m==0)
	return 0;
	if(dp[n][m]!=-1)
	return dp[n][m];
	if(s1[n-1]==s2[m-1])
	return dp[n][m]=sub(s1,s2,n-1,m-1)+1;
	else
	return dp[n][m]=max(sub(s1,s2,n-1,m),sub(s1,s2,n,m-1));	
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string s1,s2;
	cin>>s1>>s2;
	cout<<sub(s1,s2,s1.size(),s2.size());
}
