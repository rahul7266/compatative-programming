#include<bits/stdc++.h>
using namespace std;
void insertion(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	
}
int main()
{
	int i,n,a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	insertion(a,n);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
