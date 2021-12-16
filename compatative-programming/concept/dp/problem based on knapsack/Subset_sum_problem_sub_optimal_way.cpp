//finding wherther a subset with given sum exist or not
#include<bits/stdc++.h>
using namespace std;
int subset(int a[],int n,int sum)
{
	int ans;
	if(sum==0)
	return 1;
	if(n==0)
	return 0;
	if(a[n-1]<=sum)
	{
	ans=subset(a,n-1,sum-a[n-1])||subset(a,n-1,sum);
	}
	if(a[n-1]>sum)
	ans=subset(a,n-1,sum);
	return ans;
}
int main()
{
	int a[10000],n,i,sum,ans;
	cin>>n>>sum;
	for(i=0;i<n;i++)
	cin>>a[i];
	ans=subset(a,n,sum);
	if(ans)
	cout<<"yes";
	else
	cout<<"No";
}
