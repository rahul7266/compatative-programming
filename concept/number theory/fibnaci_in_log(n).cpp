#include<bits/stdc++.h>
using namespace std;
long long int m[10][10];
long long int I[10][10];
long long int f[10][10];
void mul(long long int a[][10], long long int b[][10])
{
	long long int i,j,k,c[10][10],s=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			s=0;
			for(k=0;k<2;k++)
			 s=s+a[i][k]*b[k][j];
		c[i][j]=s;	 
		}
	}
	for(i=0;i<2;i++)
	{
	 for(j=0;j<2;j++)
	    	a[i][j]=c[i][j];
	}
}
void power(long long int n)
{
	while(n!=0)
	{
		if(n%2==0)
		{
			mul(m,m);
			n=n/2;
		}
		else
		{
			mul(I,m);
			n=n-1;
		}
	}
}
void cal(long long int n)
{
	long long int i,j,k,s=0,c[10][10];
	f[0][0]=1;f[0][1]=1;
	power(n);
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		{
			s=0;
			for(k=0;k<2;k++)
			 s=s+f[i][k]*I[k][j];
		c[i][j]=s;	 
		}
	}
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
	     f[i][j]=c[i][j];	
     }
} 
int main()
{
	m[0][0]=0;m[0][1]=1;m[1][0]=1;m[1][1]=1;
	I[0][0]=1;I[0][1]=0;I[1][0]=0;I[1][1]=1;
	long long int n;
	cin>>n;
	cal(n-1);
	cout<<f[0][0]<<endl;
}
