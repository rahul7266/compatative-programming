#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int i,int j)
{
    if(i>=j)
    return 0;
    int mn=INT32_MAX;
    int k;
    int temp;
    for(k=i;k<=j-1;k++)
    {
      temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
      if(temp<mn)
      {
          mn=temp;
      }
    }
    return mn;
}
int main()
{
    int i,n,a[10001],ans;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    ans=solve(a,1,n-1);
   cout<<ans<<endl;
    return 0;
}
