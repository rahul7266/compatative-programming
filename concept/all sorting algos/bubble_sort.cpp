#include<bits/stdc++.h>
using namespace std;
void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
		if(a[j+1]<a[j])	
		swap(a[j+1],a[j]);
		}
	}
}
int main()
{
	int n,i,a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubble(a,n);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
