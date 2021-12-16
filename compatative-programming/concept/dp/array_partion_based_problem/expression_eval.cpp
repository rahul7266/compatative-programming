//no of way to get true from expression with & | ^(also knows as boolen parentrasis)
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001][4];
int solve(string s,int i,int j,int istrue)
{
 //   cout<<i<<" "<<j<<endl;
if(dp[i][j][istrue]!=-1)
    return dp[i][j][istrue];
if(i>j)
return 0;
if(i==j)
{
    if(istrue==1)
    {
        return s[i]=='T';
    }
    if(istrue==0)
    return s[i]=='F';
}
 int lt,lf,rt,rf,k,ans=0;
 for(k=i+1;k<=j-1;k=k+2)
  {
   //  cout<<k<<endl;
     if(dp[i][k-1][1]!=-1)
     lt=dp[i][k-1][1];
     if(dp[i][k-1][1]==-1)
    {
         lt=solve(s,i,k-1,1);
         dp[i][k-1][1]=lt;
    }
     if(dp[i][k-1][0]!=-1)
      lf=dp[i][k-1][0];
    if(dp[i][k-1][0]==-1)
    {
     lf=solve(s,i,k-1,0);
     dp[i][k-1][0]=lf;
    }
     if(dp[k+1][j][1]!=-1)
      rt=dp[k+1][j][1];
     if(dp[k+1][j][1]==-1){
     rt=solve(s,k+1,j,1);
     dp[k+1][j][1]=rt;
     }
     if(dp[i][k+1][0]!=-1)
      rf=dp[k+1][j][0];
     if(dp[i][k+1][0]==-1)
     {
     rf=solve(s,k+1,j,0);
     dp[k+1][j][0]=rf;
     }
     if(s[k]=='&')
     {
         if(istrue==1)
         ans+= lt*rt;
         else
         ans+= lf*rt+lf*rf+lt*rf;
     }
     if(s[k]=='|')
     {
         if(istrue==1)
         ans+= lf*rt+lt*rt+lt*rf;
         else
         ans+= lf*rf;
     }
     if(s[k]=='^')
     {
         if(istrue==1)
         ans+= lf*rt+lt*rf;
         else
         ans+= lt*rt+lf*rf;
     }  
     dp[i][j][istrue]=ans;
  }
 return ans;
}
int main()
{
    int istrue=1;
    memset(dp,-1,sizeof(dp));
    string s;
  //  cout<<"bruh"<<endl;
    cin>>s;
    cout<<solve(s,0,s.size()-1,1);
}