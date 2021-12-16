#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int n,int size)
{
     int ans;
	if(n==0||size==0)
	   return 0;
	if(size<wt[n-1])
      ans= knapsack(wt,val,n-1,size); 
    if(size>=wt[n-1])
        ans=max((knapsack(wt,val,n-1,size-wt[n-1])+val[n-1]),(knapsack(wt,val,n-1,size))); 
    return ans;

}
int main()
{
	int wt[1001],val[1001],i,n,ans,size;
	cin>>n>>size;
	for(i=0;i<n;i++)
		cin>>wt[i];
    for(i=0;i<n;i++)
        cin>>val[i];
	ans=knapsack(wt,val,n,size);
	cout<<ans<<endl;
}
