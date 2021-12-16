#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int knapsack(int wt[],int val[],int n,int size)
{
     int ans;
	if(n==0||size==0)
	   return f[0][0]= 0;
	if(f[n][size]!=-1)
	  return f[n][size];
	if(size<wt[n-1])
      ans=f[n][size]=knapsack(wt,val,n-1,size); 
    if(size>=wt[n-1])
        ans=f[n][size]=max((knapsack(wt,val,n-1,size-wt[n-1])+val[n-1]),(knapsack(wt,val,n-1,size))); 
    return ans;

}
int main()
{
    memset(f,-1,sizeof(f));
	int wt[1001],val[1001],i,n,ans,size;
	cin>>n>>size;
	for(i=0;i<n;i++)
		cin>>wt[i];
    for(i=0;i<n;i++)
        cin>>val[i];
	ans=knapsack(wt,val,n,size);
	cout<<ans<<endl;
}
