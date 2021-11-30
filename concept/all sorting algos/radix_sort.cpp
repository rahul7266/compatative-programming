#include<bits/stdc++.h>
using namespace std;
void counting_sort(int a[],int n,int exp)
{
    int b[1000];
	int count[10001]={0};
	int i;
	for(i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}
	for(i=1;i<=9;i++)
	count[i]=count[i]+count[i-1];
	for(i=n-1;i>=0;i--)
	{
     int x=(a[i]/exp)%10;
     b[count[x]-1]=a[i];
    count[x]=count[x]-1;	 		
	}
	for(i=0;i<n;i++)
	a[i]=b[i];
}
int main()
{
	
	int a[10000],i,n,num,j,k,pos,b[10000];
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(j=1;j<=100000;j=j*10)
    counting_sort(a,n,j);
    
//	for(k=0;k<=9;k++)
//	count[k]=0;
  //  }
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
   
}
