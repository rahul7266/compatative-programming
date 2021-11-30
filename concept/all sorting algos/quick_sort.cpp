#include<bits/stdc++.h>
using namespace std;
int partion(int lb,int ub,int a[])
{
	int l,r,p;
	l=lb;
	r=ub;
	p=a[lb];
	while(l<r)
	{
 		while(a[l]<=p)
 		l++;
 		while(p<a[r])
 		r--;
 		if(l<r)
		swap(a[l],a[r]);  	
	}
   swap(a[lb],a[r]);
   return r;
}
void quick_sort(int lb,int ub,int a[])
{
	int loc;
	if(lb<ub)
	{
	loc=partion(lb,ub,a);
	quick_sort(lb,loc-1,a);
	quick_sort(loc+1,ub,a);
    }
}
int main()
{
	int i,n,a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	quick_sort(0,n-1,a);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
