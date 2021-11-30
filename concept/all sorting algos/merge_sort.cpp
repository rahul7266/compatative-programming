#include<bits/stdc++.h>
using namespace std;
int b[10000];
int merge(int l,int r,int mid,int a[])
{
     int i=l,j=mid+1;
     int k=l;
     while(i<=mid&&j<=r)
	 {
       	  	if(a[i]<a[j])
       	  	{
       	  	 b[k]=a[i];
       	  	 i++;
		    }
		    else
		    {
		    	b[k]=a[j];
		    	j++;
			}
		k++;	
	 }
	 if(i>mid) 
	 {
	 	while(j<=r)
	 	{
	 		b[k]=a[j];
	 		j++;
	 		k++;
		 }
	 }
	 else
	 {
	 	while(i<=mid)
	 	{
	 		b[k]=a[i];
	 		i++;
	 		k++;
		 }
	 }
	 for(k=l;k<=r;k++)
	 {
	 	a[k]=b[k];
	 }
}
void merge_sort(int l,int r,int a[])
{
	int i,mid;
	if(l<r)
	{
		mid=(l+r)/2;
		merge_sort(l,mid,a);
		merge_sort(mid+1,r,a);
		merge(l,r,mid,a);
	}
	
}
int main()
{
	int i,n,a[10001];
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	merge_sort(0,n-1,a);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
