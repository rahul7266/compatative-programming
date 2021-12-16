#include<bits/stdc++.h>
long long int arr[100][100],I[100][100];
void sq(long long int n)
{
   long long int i,j,k,s=0,a[100][100];
     for(i=0;i<n;i++)
	  {
	   for(j=0;j<n;j++)	
	   {
	   	s=0;
	    for(k=0;k<n;k++)
		 s=s+arr[i][k]*arr[k][j];
		a[i][j]=s; 	
	   }
	  }
	  for(i=0;i<n;i++)
	  {
	   for(j=0;j<n;j++)	
	   {
	   arr[i][j]=a[i][j];	
       }
      }
}
void mul(long long int n)
{
 long long int i,j,k,s=0,II[100][100];
     for(i=0;i<n;i++)
	  {
	   for(j=0;j<n;j++)	
	   {
	   	s=0;
	    for(k=0;k<n;k++)
		   s=s+arr[i][k]*I[k][j];
		II[i][j]=s; 	
	   }
	  }
     for(i=0;i<n;i++)
	  {
	   for(j=0;j<n;j++)	
	   I[i][j]=II[i][j];	  		
     }
}
void power(long long int n,long long int x)
{
	long long int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			I[i][j]=1;
			else
			I[i][j]=0;
		}
	}
	while(x!=0)
	{
		if(x%2==0)
		{
		sq(n);//arr^2
		x=x/2;
	    }
		else
      	{
		mul(n);//I=I*arr
		x--;
	    } 
	}
}
using namespace std;
int main()
{
	long long int n,i,j,x;
	cin>>n>>x;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cin>>arr[i][j];
	}
	power(n,x);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 cout<<I[i][j]<<" ";
	 cout<<endl;	 
	}
    	
}
