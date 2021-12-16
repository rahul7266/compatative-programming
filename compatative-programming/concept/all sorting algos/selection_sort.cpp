#include<bits/stdc++.h>
using namespace std;
void selection(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
            swap(a[i],a[j]);		
		}
	}
}
int main()
{
	int a[10000],i,n;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	selection(a,n);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
