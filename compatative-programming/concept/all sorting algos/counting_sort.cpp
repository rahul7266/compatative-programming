#include<bits/stdc++.h>
using namespace std;
void counting_sort(int a[],int n,int m)
{
    int b[1000];
	int count[10001];
	int i;
	for(i=1;i<=m;i++)
	{
		count[i]=0;
		b[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		int x=a[i];
		count[x]++;
	}
	for(i=2;i<=m;i++)
	count[i]=count[i]+count[i-1];
/*	for(i=1;i<=m;i++)
	cout<<count[i]<<" ";
	cout<<endl;*/
	for(i=n;i>=1;i--)
	{
     int x=a[i];
     int y=count[x];
     b[y]=a[i];
	 count[x]--;		
	}
	for(i=1;i<=n;i++)
	a[i]=b[i];
}
int main()
{
	int n,i,a[10000],m=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]>m)
	m=a[i];
    }
	counting_sort(a,n,m);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
}
