#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int ispal(int i,int j,string s)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
int solve(int i,int j,string s)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    int k,temp,mn=1000001,l,r;
    if(i>=j)
    return 0;
    if(ispal(i,j,s))
    return 0;
    for(k=i;k<=j-1;k++)
    {
    if(dp[i][k]==-1)
    l=solve(i,k,s);
    else
    l=dp[i][k];
    if(dp[k+1][j]==-1)
    r=solve(k+1,j,s);
    else
    r=dp[k+1][j];
    temp=1+l+r;
    mn=min(mn,temp);
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;
   cout<<solve(0,s.size()-1,s);
}