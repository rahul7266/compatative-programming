#include<bits/stdc++.h>
using namespace std;
void heapify(int i,int n,int a[])
{
   int largest=i;
   int l=2*i;
   int r=2*i+1;
   if(l<=n&&a[l]>a[largest])
   largest=l;
   if(r<=n&&a[r]>a[largest])	
   largest=r;
   if(largest!=i)
   {
   	swap(a[largest],a[i]);
   	heapify(largest,n,a);
   }
}
void heap_sort(int a[],int n)
{
	int i;
	for(i=n/2;i>0;i--)
	{
		heapify(i,n,a);
	}
	for(i=1;i<n;i++)
	{
	swap(a[1],a[n-i+1]);
	heapify(1,n-i,a);	
	}
}
int main()
{
	int i,n,a[1000];
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	heap_sort(a,n);
	for(i=1;i<=n;i++)
    cout<<a[i]<<" ";
}
