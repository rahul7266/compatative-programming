#include<bits/stdc++.h>
using namespace std;
int f[10001][10001];
int subset(int a[],int n,int sum)
{
	int ans;
	if(sum==0)
	return 1;
	if(n==0)
	return 0;
	if(f[n][sum]!=-1)
	return f[n][sum];
    if(a[n-1]<=sum)
    {
    	ans=f[n][sum]=subset(a,n-1,sum-a[n-1])||subset(a,n-1,sum);
	}
	if(a[n-1]>sum)
	 ans=f[n][sum]=subset(a,n-1,sum);
	return ans;
}
int main()
{
	memset(f,-1,sizeof(f));
	int a[10001],i,n,sum,ans;
	cin>>n>>sum;
	for(i=0;i<n;i++)
	cin>>a[i];
	ans=subset(a,n,sum);
	if(ans)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
}
